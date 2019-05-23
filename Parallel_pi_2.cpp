#include <iostream>
#include <omp.h>
using namespace std;

static long num_steps = 2 << 24;

int main(int argc, char const *argv[])
{
    int i;
    double step, x, pi, sum = 0.0;

    //double t1,t2;
    //t1 = omp_get_wtime();

    step = 1.0/(double)num_steps;

    omp_set_num_threads(4);
    
    #pragma omp parallel for
    for(i = 0; i<num_steps; i++)
    {
        x = (i + 0.5)*step;
        sum += 4.0/(1.0 + x*x);
    }
    
    pi = sum * step;
    cout<<"\n Value of pi is : "<<pi;

    return 0;
}
