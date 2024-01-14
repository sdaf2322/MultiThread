#include <iostream>
#include <omp.h>
#include <math.h>

int main()
{
	const int MAX = 100000000;
	float* Data = new float[MAX];

	for (int i = 0; i < MAX; i++)
		Data[i] = i;

#pragma omp parallel
	{
#pragma omp for
		for (int i = 0; i < MAX; i++)
			Data[i] = sqrt(Data[i]);
	}

	printf("Data : %f, %f, %f, %f, %f\n", Data[0], Data[1], Data[2], Data[3], Data[4]);

	delete Data;

	return 0;
}