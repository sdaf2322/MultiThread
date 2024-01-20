#include <iostream>
#include <omp.h>
#include "math.h"

void InputData(float* Data, int Size);
void PrintData(float* Data);
void CalcSQRT(float* Data, int Size);
void CalcLOG(float* Data, int Size);

int main()
{
	const int MAX = 10000000;
	int i = 0;
	float* Data1 = new float[MAX];
	float* Data2 = new float[MAX];

	InputData(Data1, MAX);
	InputData(Data2, MAX);

	// 작업의 병렬화
#pragma omp parallel
	{
#pragma omp sections
		{
#pragma omp section
			CalcSQRT(Data1, MAX);	// 루트 계산
#pragma omp section
			CalcLOG(Data2, MAX);	// 로그 계산
		}
	}

	PrintData(Data1);
	PrintData(Data2);

	delete Data1;
	delete Data2;

	return 0;
}

void InputData(float* Data, int Size)
{
	for (int i = 0; i < Size; i++)
		Data[i] = i + 1;
}

void PrintData(float* Data)
{
	printf("Data : %f, %f, %f, %f, %f\n", Data[0], Data[1], Data[2], Data[3], Data[4]);
}

void CalcSQRT(float* Data, int Size)
{
	for (int i = 0; i < Size; i++)
		Data[i] = sqrt(Data[i]);
}

void CalcLOG(float* Data, int Size)
{
	for (int i = 0; i < Size; i++)
		Data[i] = log(Data[i]);
}