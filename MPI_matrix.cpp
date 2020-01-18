#include <mpi.h>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;


int main(int argc, char **argv)
{
  int x = 0;
  double koko;
  int rank,sum = 0, sumdiag = 0;
  int rkSize;
  int PS, LS, GS, DS;
  int tag = 99;
  srand (time(NULL));

  static const int n = 1000;
  const int PP = 2;

  MPI_Status  statRecv2;
  MPI_Request sendReq2, recReq2;
  MPI_Status  statRecv[2];
  MPI_Request reqSend[2], reqRecv[2];
  MPI_Init(0, 0);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &rkSize);

  int** A = new int*[n];
  int** B = new int*[n];
  int** C = new int*[n];

  for(int m=0;m<n;++m)
  {
    A[m] = new int[n];
  }

  for(int m=0;m<n;++m)
  {
    B[m] = new int[n];
  }

  for(int m=0;m<n;++m)
  {
    C[m] = new int[n];
  }



  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
        A[i][j] = (int)rand() % 10;
        sum = sum + A[i][j];
        B[i][j] = (int)rand() % 10;
      }
      sumdiag = sumdiag + A[i][i];
    }

    int** pra = new int*[n/PP];

    for(int m=0;m<n;++m)
    {
      pra[m] = new int[n/PP];
    }

    int** prb = new int*[n/PP];

    for(int m=0;m<n;++m)
    {
      prb[m] = new int[n/PP];
    }

    int** psa = new int*[n/PP];

    for(int m=0;m<n;++m)
    {
      psa[m] = new int[n/PP];
    }

    int** psb = new int*[n/PP];

    for(int m=0;m<n;++m)
    {
      psb[m] = new int[n/PP];
    }



  for (int i = 0; i < n / PP; i++)
  {
      for (int j = 0; j < n / PP; j++)
      {
          psa[i][j] = A[rank / PP*(n / PP) + i][rank%PP*(n / PP) + j];
          psb[i][j] = B[rank / PP*(n / PP) + i][rank%PP*(n / PP) + j];
      }
  }

  double np = rkSize;
  koko = sqrt(np);
  int k = (int)koko;


  if (rank < k)
  {
      LS = (rank + k - 1) % k;
      PS = (rank + k + 1) % k;
      GS = ((k - 1)*k) + rank;
  }
  if (rank == k)
  {
      LS = ((rank + k - 1) % k) + k;
      PS = ((rank + k + 1) % k) + k;
      GS = rank - k;
  }
  if (rank > k)
  {
      x = rank / k;
      LS = ((rank + k - 1) % k) + x * k;
      PS = ((rank + k + 1) % k) + x * k;
      GS = rank - k;
  }
  if (rank == 0 || (rank / k) < (k - 1))
  {
      DS = rank + k;
  }
  if ((rank / k) == (k - 1))
  {
      DS = rank - ((k - 1)*k);
  }
  x = 0;
  int p = 0;
  do{ //przesuniecia
      if (p < rank / PP)// w wierszu
      {

          MPI_Irecv(pra, n*n / PP / PP, MPI_FLOAT, PS, tag, MPI_COMM_WORLD, &recReq2);
          MPI_Isend(psa, n*n / PP / PP, MPI_FLOAT, LS, tag, MPI_COMM_WORLD, &sendReq2);
          MPI_Wait(&recReq2, &statRecv2);
          for (int i = 0; i < n / PP; i++)
          {
              for (int j = 0; j < n / PP; j++)
              {
                  psa[i][j] = pra[i][j];
              }
          }
  }
      MPI_Barrier(MPI_COMM_WORLD);
  if (p < rank % PP)// i w kolumnie
  {

      MPI_Irecv(prb, n*n / PP / PP, MPI_FLOAT, DS, tag, MPI_COMM_WORLD, &recReq2);
      MPI_Isend(psb, n*n / PP / PP, MPI_FLOAT, GS, tag, MPI_COMM_WORLD, &sendReq2);
      MPI_Wait(&recReq2, &statRecv2);
      for (int i = 0; i < n / PP; i++)
      {
          for (int j = 0; j < n / PP; j++)
          {
              psb[i][j] = prb[i][j];
          }
      }

  }
  MPI_Barrier(MPI_COMM_WORLD);
  p++;
  } while (p < n);


  for (int ABC = 0; ABC < PP; ABC++)
  {
      for (int i = 0; i < n / PP; i++)
      {
          for (int j = 0; j < n / PP; j++)
          {
              for (int k = 0; k < n / PP; k++)
              {
                  C[i][j] += psa[i][k] * psb[k][j];
              }
          }
      }


      MPI_Irecv(pra, n*n / PP / PP, MPI_FLOAT, PS, tag, MPI_COMM_WORLD, reqRecv);
      MPI_Irecv(prb, n*n / PP / PP, MPI_FLOAT, DS, tag, MPI_COMM_WORLD, &reqRecv[1]);
      MPI_Isend(psa, n*n / PP / PP, MPI_FLOAT, LS, tag, MPI_COMM_WORLD, reqSend);
      MPI_Isend(psb, n*n / PP / PP, MPI_FLOAT, GS, tag, MPI_COMM_WORLD, &reqSend[1]);
      MPI_Wait(reqRecv, statRecv);
      MPI_Barrier(MPI_COMM_WORLD);

      for (int i = 0; i < n / PP; i++)
      {
          for (int j = 0; j < n / PP; j++)
          {
              psa[i][j] = pra[i][j];
          }
      }


      for (int i = 0; i < n / PP; i++)
      {
          for (int j = 0; j < n / PP; j++)
          {
              psb[i][j] = prb[i][j];
          }
      }


  }


  cout << "Process: " << rank << " ";
  for (int i = 0; i < n / PP; i++)
  {
      for (int j = 0; j < n / PP; j++)
      {
          cout << C[i][j] << " ";
      }
  }
  std::cout << '\n';

  MPI_Finalize();

  if(rank == 0)
  {
    printf("\nSum of the element of the Matrix is %d\n",sum);
    printf("\nSum of diagonal element of Matrix is %d \n",sumdiag);
  }

  for(int m=0;m<n;m++)
  {
    delete[] A[m];
  }
  for(int m=0;m<n;m++)
  {
    delete[] B[m];
  }
  for(int m=0;m<n;m++)
  {
    delete[] C[m];
  }
  for(int m=0;m<n;m++)
  {
    delete[] prb[m];
  }
  for(int m=0;m<n;m++)
  {
    delete[] pra[m];
  }
  for(int m=0;m<n;m++)
  {
    delete[] psa[m];
  }
  for(int m=0;m<n;m++)
  {
    delete[] psb[m];
  }

  delete[] A;
  delete[] B;
  delete[] C;
  delete[] psa;
  delete[] psb;
  delete[] pra;
  delete[] prb;

  return 0;
}
