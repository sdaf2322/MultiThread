#include <iostream>
#include <omp.h>

int main()
{
	// 공유 메모리
	int x = 0;

	printf("main area x : %d\n", x);

	// private(x) : x라는 변수를 병렬 영역에서만 사용하는 로컬 변수로 새롭게 생성
#pragma omp parallel num_threads(2), private(x)
	{
		if (omp_get_thread_num() == 0)
			x = 1;
		else
			x = 2;

		// 로컬 영역의 x 출력
		printf("thread num : %d, x : %d\n", omp_get_thread_num(), x);
	}

	// Shared 영역의 x 출력
	printf("main area x : %d\n", x);

	return 0;
}