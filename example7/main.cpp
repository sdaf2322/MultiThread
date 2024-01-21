#include <iostream>
#include <omp.h>

int main()
{
#pragma omp parallel num_threads(2)
	{
		// �ΰ��� �����忡 ���� �ι� ���
		printf("������ ��ȣ : %d\n", omp_get_thread_num());
		
		// �ΰ��� ������ �� ���� �����ϴ� �����尡 ����
#pragma omp single
		{
			printf("������ ��ȣ : %d\n", omp_get_thread_num());
		}
	}

	return 0;
}