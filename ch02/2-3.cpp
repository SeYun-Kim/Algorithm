#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int *X;
	X = (int*)calloc(1, sizeof(int));
	if (X == NULL) {
		puts("�޸� �Ҵ翡 �����߽��ϴ�.");
	}
	else {
		*X = 57;
		printf("*X = %d\n", *X);
		free(X);
	}

	return 0;
}