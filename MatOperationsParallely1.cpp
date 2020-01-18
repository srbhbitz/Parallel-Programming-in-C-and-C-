// Parallel programming with openMP on Matrix operations with 1 method

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

int main ()
{
  int sum=0,
      diagsum=0,
      rowSizeA,
      colSizeA,
      rowSizeB,
      colSizeB,
      local_sum,
      local_diag;

  std::cout << "Input Row size of the matrix A: ";
  if (!(std::cin >> rowSizeA))
  {       /* validate EVERY user-input */
      std::cerr << "error: invalid rowSize\n";
      return 1;
  }

  std::cout << "Input Col size of the matrix A: ";
  if (!(std::cin >> colSizeA))
  {
      std::cerr << "error: invalid colSize\n";
      return 1;
  }

  std::cout << "Note: For multiplication, we need RowSize = columnSize and hence kindly make square matrix by putting column size as row size." << '\n';

  std::cout << "Input Row size of the matrix B: ";
  if (!(std::cin >> rowSizeB))
  {       /* validate EVERY user-input */
      std::cerr << "error: invalid rowSize\n";
      return 1;
  }

  std::cout << "Input Col size of the matrix B: ";
  if (!(std::cin >> colSizeB))
  {
      std::cerr << "error: invalid colSize\n";
      return 1;
  }

  int** arrayA = new int*[rowSizeA];   //declaring array dynamically.
  int** arrayB = new int*[rowSizeB];
  int** MultAxB = new int*[rowSizeA];

  for(int m=0;m<rowSizeA;++m)
  {
    arrayA[m] = new int[colSizeA];
  }

  for(int m=0;m<rowSizeB;++m)
  {
    arrayB[m] = new int[colSizeB];
  }

  for(int m=0;m<rowSizeA;++m)
  {
    MultAxB[m] = new int[colSizeB];
  }


  srand (time(NULL));
  //Creating matrix A of size rowSize x colSize with random of first 30
  for(int i = 0;i<rowSizeA;++i)
  {
    for(int j = 0;j<colSizeA;++j)
    {
      arrayA[i][j]=rand() % 10;
    }
  }

  for(int i = 0;i<rowSizeB;++i)
  {
    for(int j = 0;j<colSizeB;++j)
    {
      arrayB[i][j]=rand() % 10;
    }
  }

  std::cout << "Matrix A is of size"<< rowSizeA << " X " << colSizeA << '\n';

  //printing Matrix A
  for(int i = 0;i<rowSizeA;++i)
  {
    for(int j = 0;j<colSizeA;++j)
    {
      std::cout << arrayA[i][j] << "\t";
    }
    std::cout << '\n';
  }

  std::cout << "Matrix B is of size"<< rowSizeB << " X " << colSizeB << '\n';

  for(int i = 0;i<rowSizeB;++i)
  {
    for(int j = 0;j<colSizeB;++j)
    {
      std::cout << arrayB[i][j] << "\t";
    }
    std::cout << '\n';
  }

  #pragma omp parallel private(local_sum,local_diag) shared(sum,diagsum)
  {
  local_sum = 0;
  local_diag=0;
  //sum of element of the matrix
  #pragma omp for schedule(static,1)
  for(int i = 0;i<rowSizeA;i++)
  {
    for(int j=0;j<colSizeA;j++)
    {
      local_sum = local_sum + arrayA[i][j];
      if(i == j)
      {
          local_diag = local_diag + arrayA[i][j];
      }
    }
  }

#pragma omp single
//multiplication of mat A and mat B
  {
      if(rowSizeA!=colSizeB)
    {
      std::cout << "Multipilcation of Matrix A and Matrix B is not possible as size of Row of matrix A and size of column of matrix B does not matchs." << '\n';
    }
    else
    {
      for(int i = 0; i < rowSizeA; ++i)
      {
          for(int j = 0; j < colSizeB; ++j)
          {
              for(int k = 0; k < colSizeA; ++k)
              {
                  MultAxB[i][j] += arrayA[i][k] * arrayB[k][j];
              }
          }
      }

      std::cout << "Output of multiplication of matrix A and Matrix B is" << '\n';

      // printing of the matrix should be done after the whole calculation.
      for(int i = 0;i<rowSizeA;++i)
      {
        for(int j = 0;j<colSizeB;++j)
        {
          std::cout << MultAxB[i][j] << "\t";
        }
        std::cout << '\n';
      }
    }
  }
  #pragma omp critical
    {
      sum = sum + local_sum;
      diagsum = diagsum + local_diag;
    }
  }

  std::cout << "sum of the element of matrix  A is "<< sum << '\n';
  std::cout << "Diagonal sum for matrix A is " << diagsum <<'\n';

  std::cout << "size of matrix a is " << rowSizeA << "x" << colSizeA << "\n" << "size of matrix b is " << rowSizeB << "x" << colSizeB << "\n" << "size of matrix of AxB is " << rowSizeA << "X" << colSizeB <<'\n';

//deleting mem for the array.
  for(int m=0;m<rowSizeA;m++)
  {
    delete[] arrayA[m];
  }
  for(int m=0;m<rowSizeB;m++)
  {
    delete[] arrayB[m];
  }
  for(int m=0;m<rowSizeA;m++)
  {
    delete[] MultAxB[m];
  }

  delete[] arrayA;
  delete[] arrayB;
  delete[] MultAxB;

  return 0;
}
