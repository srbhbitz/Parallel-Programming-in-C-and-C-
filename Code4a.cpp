// a)	Throughput – every 1 second print off how many times it was able to run the solutions, run this for 10 seconds.  


#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int mat = 11;

void printMatrix(float MyArr[][mat])
{
  for (int i = 0; i < (mat-1); i++)
  {
     for (int j = 0; j <= mat-1; j++)
     {
        cout << MyArr[i][j] << "  \t  ";
     }
     cout << endl;
  }
}

int PerformOperation(float newArr[][mat])
{
    int i, j, k = 0, c, flag = 0, m = 0;
    float pro = 0;

    for (i = 0; i < mat-1; i++)
    {
        if (newArr[i][i] == 0)
        {
            c = 1;
            while (newArr[i + c][i] == 0 && (i + c) < mat-1)
                c++;
            if ((i + c) == mat-1)
            {
                flag = 1;
                break;
            }
            for (j = i, k = 0; k <= mat-1; k++)
                swap(newArr[j][k], newArr[j+c][k]);
        }

        for (j = 0; j < mat; j++)
        {

            // Excluding all i == j
            if (i != j)
            {

                // Converting Matrix to reduced row
                // echelon form(diagonal matrix)
                float pro = newArr[j][i] / newArr[i][i];

                for (k = 0; k <= mat-1; k++)
                    newArr[j][k] = newArr[j][k] - (newArr[i][k]) * pro;
            }
        }
    }
    return flag;
}


void resultPrint(float a[][mat], int flag)
{
    cout << "Result is : ";

    if (flag == 2)
      cout << "Infinite Solutions Exists" << endl;
    else if (flag == 3)
      cout << "No Solution Exists" << endl;
    else {
        for (int i = 0; i < mat-1; i++)
            cout << a[i][mat-1] / a[i][i] << "\t";
    }
}


int CheckConsistency(float a[][mat], int flag)
{
    int i, j;
    float sum;

    flag = 3;
    for (i = 0; i < mat-1; i++)
    {
        sum = 0;
        for (j = 0; j <= mat-1; j++)
            sum = sum + a[i][j];
        if (sum == a[i][j])
            flag = 2;
    }
    return flag;
}


int main()
{
  float myArray[mat-1][mat];
  double elapsed;
  int i,j,flag = 0,loop=1;
  int count = 0;
  int start,c[10]={0,0,0,0,0,0,0,0,0,0};

  start = clock()/CLOCKS_PER_SEC;

  srand((unsigned)time(NULL));


    for (i = 0; i < mat-1; i++)
    {
      for (j = 0; j < mat; j++)
      {
        myArray[i][j] = rand() % 100;
      }
    }

  while(start<10)
  {
    printMatrix(myArray);
    flag = PerformOperation(myArray);
    if (flag == 1)
    {
      flag = CheckConsistency(myArray, flag);
    }
    // Printing Final Matrix
    cout << "Final Augumented Matrix is : " << endl;
    printMatrix(myArray);
    cout << endl;
    std::cout << '\n';
    resultPrint(myArray,flag);
    std::cout << '\n';
    elapsed = (clock() - start)/CLOCKS_PER_SEC;
    for(int m = 0;m<11;m++)
    {
      if (elapsed == m)
      {
        c[m]++;
        count = count + c[m];
      }
    }
  start = clock()/CLOCKS_PER_SEC;
  }
  count= 0;
  for (int i=0;i<10;i++)
 {
   std::cout << "for second " << i + 1 << ", loop ran for " << c[i] << '\n';
   count = count + c[i];
  }

  std::cout << "In one second, loop ran for " << count <<" times" << "\n";


  return 0;

}
