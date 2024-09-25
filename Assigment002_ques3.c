#include<stdio.h>
#include<stdlib.h>

//left shifting and printing function
void TWOmultipler(int N)
{
    unsigned long long int current = 1;
    for(int i=0; i<N; i++)
    {
        printf("\n%llu",current);
        current = current<<1;
    }
    return;
}

int main(void)
{
    int N;

    //taking input from user
    printf("Enter 'N' for processing : ");
    scanf("%d", &N);

    //left shift function call
    TWOmultipler(N);

    return 0;
}
