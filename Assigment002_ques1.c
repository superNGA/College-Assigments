#include<stdio.h>
#include<stdlib.h>

//smallest element
int Minimumelement(int* mainARRAY, int size)
{
    int temp = mainARRAY[0];

    for(int i =0; i<size; i++)
    {
        if(mainARRAY[i] < temp)
        {
            temp = mainARRAY[i];
        }
    }

    return temp;
}

//largest element
int Maximumlement(int* mainARRAY, int size)
{
    int temp = mainARRAY[0];

    for(int i =0; i<size; i++)
    {
        if(mainARRAY[i] > temp)
        {
            temp = mainARRAY[i];
        }
    }

    return temp;
}

//smallest and largest at the same time
int MinAndMaxAtSameTime(int* mainARRAY, int size)
{
    int tempmin = mainARRAY[0], tempmax= mainARRAY[0];

    for( int i =0; i<size; i++)
    {
        if(mainARRAY[i] > tempmax)
        {
            tempmax = mainARRAY[i];
        }else if(mainARRAY[i] < tempmin)
        {
            tempmin = mainARRAY[i];
        }
    }

    printf("Max & Min are : %d & %d\n\n", tempmax, tempmin);
    return 1;
}

//mean of array
float Mean(int* mainARRAY, int size)
{
    float counter = 0.000000;

    for( int i =0; i<size; i++)
    {
        counter += mainARRAY[i];
    }

    return (float)(counter/size);
}

//varience of an array
float variance(int* mainARRAY, int size)
{
    float counter=0;
    float mean = Mean(mainARRAY, size);

    //find variance
    for(int i =0; i<size; i++)
    {
        counter += (mainARRAY[i] - mean) * (mainARRAY[i] - mean);
    }
    return counter/size;
}

//sum of square of elements of an array
int SumofSquares(int* mainARRAY, int size)
{
    int counter = 0;
    for( int i =0; i<size; i++)
    {
        counter += mainARRAY[i] * mainARRAY[i];
    }
    return counter;
}

//harmonic mean of array
float HarmonicMean(int* mainARRAY, int size)
{
    float counter=0;
    for( int i = 0; i<size; i++)
    {
        counter += 1/(float)mainARRAY[i];
    }
    return size/counter;
}

int main(void)
{
    int N; //number of elements in the array
    printf("Number of elements for the array : ");
    scanf("%d", &N);
    int* mainARRAY = (int*)malloc(N * sizeof(int));

    //inputing elements in the array
    for(int i =0; i<N; i++)
    {
        printf("%d th element : ", i);
        scanf("%d", &mainARRAY[i]);
    }

    //minimum function call
    printf("\n\nminimum : %d\n\n", Minimumelement(mainARRAY, N));

    //maximum function call
    printf("maximum : %d\n\n", Maximumlement(mainARRAY, N));

    //min and max at 1 go
    MinAndMaxAtSameTime(mainARRAY, N);

    //mean function call
    printf("Mean is : %.2f\n\n", Mean(mainARRAY, N));

    //variance function call
    printf("variance : %.2f\n\n", variance(mainARRAY, N));

    //Sum of squres function call
    printf("sum of squares : %d\n\n", SumofSquares(mainARRAY, N));

    //Harmonic mean function call
    printf("Harmonic mean : %.2f\n\n", HarmonicMean(mainARRAY, N));

    //freeing memory ( very important )
    free(mainARRAY);
    return 0;
}
