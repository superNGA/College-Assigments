#include<stdio.h>
#include<stdlib.h>

float pow(float x, int N)
{
	float temp = 1;
	for (int i = 0; i < N; i++)
	{
		temp *= x;
	}
	return temp;
}

float algo(float x, int N)
{
	int counter = 1;

	for (int i = 1; i <= N; i++)
	{
		counter *= i;
	}

	return pow(x, N) / counter;
}

int main(void)
{
	float x;
	int N;
	printf("Enter 'x' : ");
	scanf("%f", &x);
	printf("Enter 'N' : ");
	scanf("%d", &N);

	printf("answer : %f\n", algo(x, N));

	return 0;
}
