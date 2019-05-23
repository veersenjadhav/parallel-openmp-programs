#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a[100][100];
    int b[100][100];
    int m[100][100];

    for(int i = 0; i < 100; i++)
    {
        
        for(int j = 0; j < 100; j++)
        {
            a[i][j] = rand();
            b[i][j] = rand();
        }
        
    }

    // Multiplicattion of matrix
    
    for(int k = 0; k < 100; k++)
    {
        
        for(int i = 0; i < 100; i++)
        {
            int sum = 0;
            for(int j = 0; j < 100; j++)
            {
                sum += a[i][j] * b[j][i];
            }
            m[k][i] = sum;
            
        }
        
    }
    
    for(int i = 0; i < 100; i++)
    {
        
        for(int j = 0; j < 100; j++)
        {
            printf("\n %d",m[i][j]);
        }
        
    }

    return 0;
}
