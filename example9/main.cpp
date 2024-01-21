#include <iostream>
#include <omp.h>
#include "math.h"

int main()
{
	const int MAX = 100000000;
	float* data;
	data = new float[MAX];

	for (int i = 0; i < MAX; i++)
		data[i] = i;

#pragma omp parallel num_threads(4)
	{
#pragma omp for
			for (int i = 0; i < MAX; i++)
				data[i] = sqrt(data[i]);
		// 마스터 스레드만 결과 출력
#pragma omp master
			for (int i = 0; i < 5; i++)
				printf("data[%d] = %.4f\n", i, data[i]);
		// 마스터 스레드가 동작을 수행하는 동안 다른 스레드 대기
#pragma omp barrier
#pragma omp for
			for (int i = 0; i < MAX; i++)
				data[i] = log(data[i]);
	}

	delete data;
	
	return 0;

}