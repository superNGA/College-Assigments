#include<stdio.h>
#include<stdlib.h>

//finding factorial inverse
float FactINVERSE(int N)
{
    float counter = 1;
    for (int i = 1; i <= N; i++)
    {
        counter *= i;
    }
    return 1 / counter;
}

int main(void)
{
    int N;

    //getting input from user
    printf("Enter 'N' for processing : ");
    scanf("%d", &N);

    printf("\nFactorial Inverse till 'N' : %.4f", FactINVERSE(N));

    return 0;
}
