// C program to implement Runge Kutta method Parallely with For 

#include<stdio.h>
#include<omp.h>
#include<cmath>

#define NUM_THREADS 4

// A sample differential equation "dy/dx = (x - y)/2"
float dydx(float x, float y)
{
	return((x - y)/2);
}

// Driver method
int main()
{
	float x0 = 0, y = 1, x = 2.4, h = 0.0001;//temp[NUM_THREADS]={2,2};
	int nthreads;
	omp_set_num_threads(NUM_THREADS);
	// Finds value of y for a given x using step size h
	// and initial value y0 at x0.
	// Count number of iterations using step size or
	// step height h
	int n = (int)((x - x0) / h),c=0,temp =floor(n/4);
	float k1, k2, k3, k4, k5;

	#pragma omp parallel
	{
		int id,nthrds;
		// Iterate for number of iterations
		id = omp_get_thread_num();
		nthrds = omp_get_num_threads();

				#pragma omp for collapse(2)
				for(int i=0; i<temp;i++)
					{
						// Apply Runge Kutta Formulas to find
						// next value of y
						for(id=0; id<nthrds;id++)
						{
							k1 = h*dydx(x0, y);
							k2 = h*dydx(x0 + 0.5*h, y + 0.5*k1);
							k3 = h*dydx(x0 + 0.5*h, y + 0.5*k2);
							k4 = h*dydx(x0 + h, y + k3);


							// Update next value of y
							#pragma omp critical
							{
							//c++;

							y = y + (1.0/6.0)*(k1 + 2*k2 + 2*k3 + k4);
							/* /printf(" \n K1 = %f, \t K2 = %f, \t K3 = %f, \t K4 = %f and \t Y = %f" , k1 , k2 , k3 , k4 , y );
							//printf("\n value of n =%d and id is %d \n and value of I is %d",n, id, c);*/
							// Update next value of x
							x0 = x0 + h;}
						}
					}
				}


	//y = temp[0] + temp[1] + temp[2] + temp[3];
	printf("\nThe value of y at x is : %f",y);
	printf("\n");
	return 0;
}
