#include<stdio.h>
#include<omp.h>

int main(int argc, char const *argv[])
{
    int size = 2<<24;
    double *arrayA = (double *)malloc(size*sizeof(double));
    double *arrayB = (double *)malloc(size*sizeof(double));
    double *arrayC = (double *)malloc(size*sizeof(double));

    
    for(int i = 0; i < size; i++)
    {
        arrayA[i] = 1.0;
        arrayB[i] = 2.0;
        arrayC[i] = 0.0;
    }
    

    return 0;
}
