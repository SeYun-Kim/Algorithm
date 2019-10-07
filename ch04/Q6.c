#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "IntDequeue.h"

int main(void)
{
	IntDequeue que;

	if (Initialize(&que, 64) == -1) {
		puts("ť�� ������ �����߽��ϴ�.");
		return 1;
	}

	while (1) {
		int m, x;
		int idx;

		printf("���� �������� �� : %d / %d\n", Size(&que), Capacity(&que));
		printf("(1)�� �տ� ������ ��ť (2)�� ���� ������ ��ť (3)�� �� ��ũ (4)���\n"
			"(5)�� �ڿ� ������ ��ť (6)�� ���� ������ ��ť (7)�� �� ��ũ (8)�˻�\n"
			"(9)�ʱ�ȭ (10)��� �ִ� ���� / ���� �� ���� (0)���� : ");
		scanf("%d", &m);

		if (m == 0) break;

		switch (m) {
		case 1:
			printf("�����ͣ�");   scanf("%d", &x);
			if (EnqueFront(&que, x) == -1)
				puts("\a���� : ��ť�� �����߽��ϴ�.");
			break;

		case 2:
			if (DequeFront(&que, &x) == -1)
				puts("\a���� : ��ť�� �����߽��ϴ�.");
			else
				printf("��ť�� �����ʹ� %d�Դϴ�.\n", x);
			break;

		case 3:
			if (PeekFront(&que, &x) == -1)
				puts("\a���� : ��ũ�� �����߽��ϴ�.");
			else
				printf("��ũ�� �����ʹ� %d�Դϴ�.\n", x);
			break;

		case 4:
			Print(&que);
			break;

		case 5:
			printf("data��");   scanf("%d", &x);
			if (EnqueRear(&que, x) == -1)
				puts("\a���� : ��ť�� �����߽��ϴ�.");
			break;

		case 6:
			if (DequeRear(&que, &x) == -1)
				puts("\a���� : ��ť�� �����߽��ϴ�.");
			else
				printf("��ť�� �����ʹ� %d�Դϴ�.\n", x);
			break;

		case 7:
			if (PeekRear(&que, &x) == -1)
				puts("\a���� : ��ũ�� �����߽��ϴ�.");
			else
				printf("��ũ�� �����ʹ� %d�Դϴ�.\n", x);
			break;

		case 8:
			printf("�˻� �����ͣ�");
			scanf("%d", &x);
			if ((idx = Search(&que, x)) == -1)
				puts("\a���� : �˻��� �����߽��ϴ�.");
			else {
				printf("�����ʹ� �ε��� %d ��ġ�� �ֽ��ϴ�.\n", idx);
				printf("ť�� �� �տ��� %d��ŭ �ڿ� ��ġ�մϴ�.\n", Search2(&que, x));
			}
			break;

		case 9:
			Clear(&que);
			break;

		case 10:
			printf("ť�� ��� ��%s.\n", IsEmpty(&que) ? "���ϴ�" : "�� �ʽ��ϴ�");
			printf("ť�� ���� %s.\n", IsFull(&que) ? "á���ϴ�" : "���� �ʾҽ��ϴ�");
			break;
		}
	}

	Terminate(&que);

	return 0;
}