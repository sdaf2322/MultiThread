#include <iostream>
#include <omp.h>

int main()
{
	// ���� �޸�
	int x = 0;

	printf("main area x : %d\n", x);

	// ����� ������ ���� ����
#pragma omp parallel num_threads(2)
	{
		// 0�� ������� x���� 1�� ����
		if (omp_get_thread_num() == 0)
			x = 1;
		// 1�� ������� x���� 2�� ����
		else if(omp_get_thread_num() == 1)
			x = 2;

		// ������ ��ȣ�� x���� ���
		printf("Num %d thread area x : %d\n", omp_get_thread_num(), x);
	}

	// ���� ���� �ۿ��� x�� ���
	printf("main area x : %d\n", x);

	return 0;
}