#include <iostream>
#include <omp.h>
#define NUM_THREADS 4
using namespace std;

static long num_steps = 2 << 24;

int main(int argc, char const *argv[])
{
    int i, total_threads;
    double step, fsum, x, pi, sum[NUM_THREADS];

    step = 1.0/(double)num_steps;

    omp_set_num_threads(NUM_THREADS);

    #pragma omp paralle
    {
        int i,id = omp_get_num_threads();
        int nThreads = omp_get_num_threads();

        double x;
        sum[id] = 0.0;

        if(id == 0)
        {
            total_threads = nThreads;
        }

        for(i = id; i < num_steps; i += total_threads)
        {
            x = (i + 0.5) * step;
            sum[id] += 4.0 / (1.0 + x*x);
        }
    }

    for(i = 0; i<NUM_THREADS; i++)
    {
        
    }

    /* for(i = 0; i<num_steps; i++)
    {
        x = (i + 0.5)*step;
        sum+= 4.0/(1.0 + x*x);
    }*/

    cout<<"\n Value of pi is : "<<pi;

    return 0;
}