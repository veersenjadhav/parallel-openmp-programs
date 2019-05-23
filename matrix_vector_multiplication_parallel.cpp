#include<iostream>
#include<omp.h>
using namespace std;

#define N 1000
float A[N][N], B[N][0], C[N][0];
int main ()
{
    int i, j, m;

    srand ( time(NULL) );
    for(i=0;i<N;i++) 
    {
        for(j=0;j<N;j++) 
        {
            A[i][j]= (rand()%10);
        }
    }

    srand ( time(NULL) );
    for(i=0;i<N;i++) 
    {
        B[i][0]= (rand()%10);
    }

    cout<<"\n Max number of threads: "<<omp_get_max_threads();
    #pragma omp parallel
        cout<<"\n Number of threads: "<<omp_get_num_threads();

    #pragma omp parallel for private(m)
    for(i=0;i<N;i++) 
    {
        C[i][0]=0.;
        for(m=0;m<N;m++) 
        {
            C[i][0]=A[i][m]*B[m][0]+C[i][0];
        }
        // cout<<"\n C: "<<C[i][0];
    }

    return 0;
}