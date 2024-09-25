#include<stdio.h>
#include<stdlib.h>

//sum of first N natural numbers
int NaturalSum(int N)
{
    return (N*(N+1))/2;
}

//sum of first N odd numbers
int OddSum(int N)
{
    return N*N;
}

//Sum of first N even numbers
int EvenSum(int N)
{
    return 2*NaturalSum(N);
}

//harmonic sum of N elements
float HarmonicSum(int N)
{
    float counter =0 ;
    for(float i =1; i<=N; i++)
    {
        counter += 1/i;
    }
    return counter;
}

int main(void)
{
    int N;

    //getting input from user
    printf("Enter 'N' for processing : ");
    scanf("%d", &N);

    //Natural sum function call
    printf("\nSum of first N numbers : %d\n\n", NaturalSum(N));

    //Odd number sum function call
    printf("Sum of first N ODD numbers : %d\n\n", OddSum(N));

    //Even numver sum function call
    printf("Sum of first N EVEN numbers : %d\n\n", EvenSum(N));

    //Harmonic series sum function call
    printf("Sum of first N HARMONIC numbers : %.2f\n\n", HarmonicSum(N));

    return 0;
}
