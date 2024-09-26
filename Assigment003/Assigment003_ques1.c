#include<stdio.h>
#include<stdlib.h>

//Iterative approach
int Iterative(int N)
{
    int counter = 1;
    for( int i =1; i<=N;i++)
    {
        counter *= i;
    }
    return counter;
}

//recursive approach
void Recursive(int N, int* counter)
{
    if(N == 0)
    {
        return;
    }
    (*counter) *= N;
    N--;
    Recursive(N, counter);
}

int main(void)
{
    int N, counter =1;

    //getting input from user
    printf("Enter 'N' for processing : ");
    scanf("%d", &N);

    //Iterative function call
    printf("\nIteraive way : %d\n", Iterative(N));

    //Recursive function call
    Recursive(N, &counter);
    printf("\nRecursive way : %d", counter);

    return 0;
}
