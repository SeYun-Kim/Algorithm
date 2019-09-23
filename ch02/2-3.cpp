#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int *X;
	X = (int*)calloc(1, sizeof(int));
	if (X == NULL) {
		puts("메모리 할당에 실패했습니다.");
	}
	else {
		*X = 57;
		printf("*X = %d\n", *X);
		free(X);
	}

	return 0;
}