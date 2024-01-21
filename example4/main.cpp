#include <iostream>
#include <omp.h>

int Fibonacci(int n);

int main()
{
	const int MAX = 41;
	int FibNumber[MAX] = { 0 };
	int i = 0;

#pragma omp parallel
	{
#pragma omp single private(i)
		for (i = 1; i < MAX; i++)
		{
			FibNumber[i] = Fibonacci(i);
		}
	}

	printf("피보나치 수 : ");
	for (int i = 0; i < MAX; i++)
		printf("%d", FibNumber[i]);

	return 0;
}

int Fibonacci(int n)
{
	int x;
	int y;

	if (n < 2)
		return n;
	else
	{
#pragma omp task shared(x)
		x = Fibonacci(n - 1);
#pragma omp task shared(y)
		y = Fibonacci(n - 2);
#pragma omp taskwait
		return x + y;
	}
}