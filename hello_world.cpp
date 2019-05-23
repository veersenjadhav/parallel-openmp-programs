#include<iostream>
#include<omp.h>
using namespace std;

int main(int argc, char const *argv[])
{

    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        cout<<"Hello "<<id<<"\n";
        cout<<"World "<<id<<"\n";
    }
    return 0;
}