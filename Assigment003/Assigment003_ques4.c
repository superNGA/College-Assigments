#include<stdio.h>
#include<stdlib.h>

int factorialCHECKER(float M)
{
    //handling stupid cases
    if(M == 1){return M;}
    float nums = 2;
    while(1)
    {
        if(M - (int)M != 0)
        {
            return 80085;
        }
        M /= nums;
        if(M == 1){break;} //breaking condition
        nums++;
    }
    return nums;
}

int main(void)
{
    float M;

    //getting input from user
    printf("Enter 'M' for processing : ");
    scanf("%f", &M);

    int answer = factorialCHECKER(M);
    if(answer != 80085)
    {
        printf("'M' is a factorial of : %d", answer);
    }else
    {
        printf("'M' is not a factorial of any interger");
    }

    return 0;
}
