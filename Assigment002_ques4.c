#include<stdio.h>
#include<stdlib.h>

int Waver(int N)
{
    int counter = 0;
    int currentNUM =1;
    int Adder = 2;

    for(int i = 0; i<N; i++)
    {
        counter += currentNUM; //Adding up the series
        currentNUM += Adder; //Getting the next odd number
        currentNUM *= -1; //switching signs
        Adder *= -1; //switching sign of the addition number
    }

    return counter;
}

int main(void)
{
    int N;

    //getting input from the user
    printf("Enter N for processing : ");
    scanf("%d", &N);

    //addition function call
    printf("\nSum of the series : %d", Waver(N));

    return 0;
}
