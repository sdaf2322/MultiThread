#include <iostream>
#include <omp.h>

int main()
{
#pragma omp parallel num_threads(2)
	{
		// 두개의 스레드에 의해 두번 출력
		printf("스레드 번호 : %d\n", omp_get_thread_num());
		
		// 두개의 스레드 중 먼저 도착하는 스레드가 실행
#pragma omp single
		{
			printf("스레드 번호 : %d\n", omp_get_thread_num());
		}
	}

	return 0;
}