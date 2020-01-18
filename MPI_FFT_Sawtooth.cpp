#include <mpi.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include <vector>
#include <time.h>
#include <cstdlib>
#include <bitset>

using namespace std;

 int reverse_bit( int val), w_pow =0, mask=0x00000001;

int main()
{
  int process_id,  process_size, FROM, TO, real_from, real_to,length_p=128, bitlength, length_p2=0;

  double s_time;
  double * real_data_in;
  double * img_data_in;
  double * real_data_out;
  double * img_data_out;
  double * real_buffer;
  double * img_buffer;
  double * rb_real_buffer;
  double * rb_img_buffer;

  MPI_Init(NULL, NULL);


  MPI_Comm_size(MPI_COMM_WORLD, &process_size);

  MPI_Comm_rank(MPI_COMM_WORLD, &process_id);

  w_pow = ceil(log((double)length_p)/log(2.0));
  length_p2=(int)pow(2.0, ceil(log((double)length_p)/log(2.0)));

  bitlength = log(length_p2) / log(2);





  int ws_temp = process_size;

  if ( length_p2 < process_size )
  {
    ws_temp = length_p2;

  }
  else
  {
    ws_temp = pow(2.0, floor(log((double)process_size)/log(2.0)));
  }


  if(process_id > ws_temp-1)
   {

    cout << process_id << ": ---- Bye! ---- " << endl;
    MPI_Finalize();
    exit(1);
    }

 int dataslice = length_p2 / ws_temp;
FROM = dataslice*process_id;
TO = FROM + dataslice;

if (process_id == 0)
  {
    cout << "Power of 2 is: " << w_pow << endl;
    cout << "No. of threads: " << ws_temp << endl;
  }
real_data_in = new double[length_p2];

img_data_in = new double[length_p2];

real_data_out = new double[length_p2];

img_data_out = new double[length_p2];

real_buffer = new double[length_p2];

img_buffer = new double[length_p2];

rb_real_buffer = new double[length_p2];

rb_img_buffer = new double[length_p2];



  int puf_l = length_p2;
  int divider = 0;
  int ind=0 ;

  for(int i=0;i<length_p;i++)
  {
    real_data_in[i] = (double)i;
    img_data_in[i] = 0;
  }
  for(int i=length_p;i<length_p2;i++)
  {
    real_data_in[i] = 0;
    img_data_in[i] = 0;
  }

 for( int i=0;i<length_p2;i++)
   {
     ind = reverse_bit(i);
     rb_real_buffer[i]=real_data_in[ind];
     rb_img_buffer[i]=img_data_in[ind];
   }

  for( int n=FROM;n<TO;n=n+5)
  {

    for( int i=0;i<length_p2;i++)
    {
      real_buffer[i]=rb_real_buffer[i];
      img_buffer[i]=rb_img_buffer[i];
    }
     divider=1;
     puf_l = length_p2;
     for( int b=0;b<w_pow;b++)
     {
       divider = divider*2;
       for( int k=0;k<puf_l;k++)
         {
         real_buffer[k] = real_buffer[2*k] + real_buffer[2*k+1]* ( (double)cos( 2*M_PI*n /divider ))- img_buffer[2*k+1]*((double)sin( 2*M_PI*n /divider ));
         }
      puf_l = puf_l / 2;
     }
   real_data_out[n]=real_buffer[0];
   img_data_out[n]=img_buffer[0];



   }


  if(ws_temp>1)
  {
     for(int p=1;p<ws_temp;p++)
       {
         if(process_id == p)
           {

             MPI_Send(&real_data_out[FROM], dataslice, MPI_DOUBLE, 0 , 900 , MPI_COMM_WORLD);
             MPI_Send(&img_data_out[FROM], dataslice, MPI_DOUBLE, 0 , 900 , MPI_COMM_WORLD);

           }
         else if ( process_id == 0)
           {

             real_from = dataslice*p;
             real_to = dataslice*(p+1);

             MPI_Recv(&real_data_out[real_from], dataslice, MPI_DOUBLE, p , 900 , MPI_COMM_WORLD,MPI_STATUS_IGNORE);
             MPI_Recv(&img_data_out[real_from], dataslice, MPI_DOUBLE, p , 900 , MPI_COMM_WORLD,MPI_STATUS_IGNORE);
         }
     }
   }

   if(process_id == 0)
   {
     for(int n=0;n<length_p2;n=n+5)
     if((real_data_out[n] || img_data_out[n]) == 0) break;
     else
     cout << "-- Input " << n << ": " << real_data_in[n] << "," << img_data_in[n] << " -- output: " << real_data_out[n] << "," << img_data_out[n] << endl;
   }


   delete[] img_data_out;
   delete[] real_data_out;
   delete[] img_data_in;
   delete[] real_data_in;
   delete[] real_buffer;
   delete[] img_buffer;
   delete[] rb_real_buffer;
   delete[] rb_img_buffer;


  MPI_Finalize();

  return 0;
 }

 /*------------------------Function reverse_bit-----------------------------------------------*/
 int reverse_bit( int val)
 {
    int real_val=0, f_val=0;
   for(int i=0;i<w_pow;i++)
   {
     real_val = (val >> i) & mask;
     f_val = f_val | (real_val << (w_pow-i-1));
   }
 return f_val;
 }
