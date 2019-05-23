#include <iostream>
#include <omp.h>
#define NUM_THREADS 4
using namespace std;

int main(int argc, char const *argv[])
{
    int i,N = 10;
    omp_set_num_threads(NUM_THREADS);

    #pragma omp parallel for schedule(dynamic, 2)
    for(i=0; i<N; i++)
    {
        int id = omp_get_thread_num();
        cout<<"Thread id : "<<id<<" Iteration : "<<i<<"\n";
    }

    return 0;
}