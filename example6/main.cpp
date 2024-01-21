#include <iostream>
#include <omp.h>

int main()
{
	// ���� �޸�
	int x = 0;

	printf("main area x : %d\n", x);

	// private(x) : x��� ������ ���� ���������� ����ϴ� ���� ������ ���Ӱ� ����
#pragma omp parallel num_threads(2), private(x)
	{
		if (omp_get_thread_num() == 0)
			x = 1;
		else
			x = 2;

		// ���� ������ x ���
		printf("thread num : %d, x : %d\n", omp_get_thread_num(), x);
	}

	// Shared ������ x ���
	printf("main area x : %d\n", x);

	return 0;
}