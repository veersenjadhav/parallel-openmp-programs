#include<iostream>
#include<omp.h>
using namespace std;

int main(int argc, char const *argv[])
{
    
    omp_set_num_threads(4);

    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        cout<<id<<"\n";
    }

    return 0;
}
