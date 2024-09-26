#include<stdio.h>
#include<stdlib.h>

//helper factorial function
int factorial(int num)
{
    int counter =1;
    for(int i=1; i<= num; i++)
    {
        counter *= i;
    }
    return counter;
}

//finding combination
float Combination_comput(int N, int R)
{
    //stupid cases
    if(R==0){return 0;}

    float counter=1;
    for( int i = N-R+1; i<= N; i++)
    {
        counter *= i;
    }

    return counter/(float)factorial(R);
}

int main(void)
{
    int N, R;
    printf("Enter 'N' for nCr : ");
    scanf("%d", &N);
    printf("Enter 'R' for nCr : ");
    scanf("%d", &R);

    float answer = Combination_comput(N,R);
    if(answer == 0)
    {
        printf("invalid value");
    }
    printf("nCr : %.2f", answer);
    return 0;
}
