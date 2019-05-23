#include<iostream>
#include<omp.h>
#define N 800
using namespace std;

int main() {
   float a[N][N], l[N][N], u[N][N];
   int i = 0, j = 0;

    srand ( time(NULL) );
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            a[i][j]= (rand()%10);
        }
    }

    cout<<"\n Max number of threads: "<<omp_get_max_threads();
    #pragma omp parallel
        cout<<"\n Number of threads: "<<omp_get_num_threads();
   
    int k = 0; i = 0; j = 0;
    #pragma omp parallel for private(j,k)
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (j < i)
                l[j][i] = 0;
            else {
                l[j][i] = a[j][i];
                for (k = 0; k < i; k++) {
                    l[j][i] = l[j][i] - l[j][k] * u[k][i];
                }
            }
        }

        for (j = 0; j < N; j++) {
            if (j < i)
                u[i][j] = 0;
            else if (j == i)
                u[i][j] = 1;
            else {
                u[i][j] = a[i][j] / l[i][i];
                for (k = 0; k < i; k++) {
                    u[i][j] = u[i][j] - ((l[i][k] * u[k][j]) / l[i][i]);
                }
            }
        }
    }

    /*
    cout << "L Decomposition..."<<endl;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cout<<l[i][j]<<" ";
        }
        cout << endl;
    }
    cout << "U Decomposition..."<<endl;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cout<<u[i][j]<<" ";
        }
        cout << endl;
    }
    */

   return 0;
}