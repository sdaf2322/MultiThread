#include <iostream>
#include <omp.h>

int main()
{
	// 공유 메모리
	int x = 0;

	printf("main area x : %d\n", x);

	// 사용할 스레드 개수 설정
#pragma omp parallel num_threads(2)
	{
		// 0번 스레드는 x값을 1로 변경
		if (omp_get_thread_num() == 0)
			x = 1;
		// 1번 스레드는 x값을 2로 변경
		else if(omp_get_thread_num() == 1)
			x = 2;

		// 스레드 번호와 x값을 출력
		printf("Num %d thread area x : %d\n", omp_get_thread_num(), x);
	}

	// 병렬 영역 밖에서 x값 출력
	printf("main area x : %d\n", x);

	return 0;
}