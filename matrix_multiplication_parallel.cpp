#include<iostream>
#include<omp.h>
using namespace std;

#define N 3
float A[N][N], B[N][N], C[N][N];
int main ()
{
    int i, j, m;

    srand ( time(NULL) );
    for(i=0;i<N;i++) 
    {
        for(j=0;j<N;j++) 
        {
            A[i][j]= (rand()%10);
            B[i][j]= (rand()%10);
        }
    }

    cout<<"\n Max number of threads: "<<omp_get_max_threads();
    #pragma omp parallel
        cout<<"\n Number of threads: "<<omp_get_num_threads();

    #pragma omp parallel for private(m,j)
    for(i=0;i<N;i++) 
    {
        for(j=0;j<N;j++) 
        {
            C[i][j]=0.;
            for(m=0;m<N;m++) 
            {
                C[i][j]=A[i][m]*B[m][j]+C[i][j];
            }
            cout<<"\n C: "<<C[i][j];
        }
    }

    return 0;
}
