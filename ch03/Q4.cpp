#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int bin_search(const int a[], int n, int key)
{
	int i;
	int pl = 0;
	int pr = n - 1;
	int pc;

	printf("   |");
	for (i = 0; i < n; i++) printf("%4d", i);
	printf("\n---+");
	for (i = 0; i < n; i++) printf("----", i);
	printf("--\n");

	do {
		pc = (pl + pr) / 2;

		printf("   |");
		for (i = 0; i < 4 * pl; i++) printf(" ");
		printf(" <-");
		for (i = 0; i < 4 * (pc - pl); i++) printf(" ");
		printf("+");
		for (i = 0; i < 4 * (pr - pc) - 2; i++) printf(" ");
		printf("->\n");

		printf("%3d|", pc);
		for (i = 0; i < n; i++)
			printf("%4d", a[i]);
		putchar('\n');

		if (a[pc] == key)
			return pc;
		else if (a[pc] < key)
			pl = pc + 1;
		else
			pr = pc - 1;
	} while (pl <= pr);

	return -1;
}

int main(void)
{
	int i, nx, ky, idx;
	int *x;

	puts("2�� �˻�");
	printf("��Ҽ� : ");
	scanf("%d", &nx);
	x = (int *)calloc(nx, sizeof(int));

	printf("������������ �Է��ϼ���.\n");
	printf("x[0] : ");
	scanf("%d", &x[0]);

	for (i = 1; i < nx; i++) {
		do {
			printf("x[%d] : ", i);
			scanf("%d", &x[i]);
		} while (x[i] < x[i - 1]);
	}
	printf("�˻� �� : ");
	scanf("%d", &ky);

	idx = bin_search(x, nx, ky);

	if (idx == -1)
		puts("�˻��� �����߽��ϴ�.");
	else
		printf("%d�� x[%d]�� �ֽ��ϴ�.\n", ky, idx);

	free(x);

	return 0;
}