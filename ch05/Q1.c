#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


int factorial(int n)
{
	int i =0;
	int result = 1;

	for (i = n; i > 0; i--)
	{
		result *= i;
	}
	return result;
}

int main(void)
{
	int x;
	printf("������ �Է��ϼ��䣺");
	scanf("%d", &x);
	printf("%d�� �������� ���� %d�Դϴ�.\n", x, factorial(x));

	return 0;
}
