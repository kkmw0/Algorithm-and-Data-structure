#include <stdio.h>
#include <stdlib.h>
#include "IntQueue.h"
int main(void) {
	IntQueue q;
	if (Initialize(&q, 64) == -1) {
		puts("ť ���� ����.");
		return 1;
	}

	while (1) {
		int menu, x, key, idx;
		printf("���� ������ �� : %d / %d\n", Size(&q), Capacity(&q));
		printf("(1)��ť  (2)��ť  (3)��ũ  (4)���  (5)�˻�  (0)���� : ");
		scanf_s("%d", &menu);

		if (menu == 0) break;
		switch (menu)
		{
		case 1: /* ��ť */
			printf("������ : ");
			scanf_s("%d", &x);

			if (Enque(&q, x) == -1)
				puts("���� : ��ť�� �����Ͽ����ϴ�.");
			break;

		case 2: /* ��ť */
			if (Deque(&q, &x) == -1)
				puts("���� : ��ť�� �����Ͽ����ϴ�.");
			else
				printf("��ť�� �����ʹ� %d�Դϴ�.\n", x);
			break;

		case 3: /* ��ũ */
			if (Peek(&q, &x) == -1)
				puts("���� : ��ũ�� �����Ͽ����ϴ�.");
			else
				printf("��ũ �����ʹ� %d�Դϴ�.\n", x);
			break;

		case 4: /* ��� */
			Print(&q);
			break;

		case 5: /* �˻� */
			printf("�˻��� ������ �Է� : ");
			scanf_s("%d", &key);

			idx = Search(&q, key);
			if (idx == -1)
				printf("%d�� ť�� ���������ʽ��ϴ�.\n", key);
			else {
				printf("�˻�����!\n");
				printf("%d�� que[%d]�� �ֽ��ϴ�.\n", key, idx);
			}
		}
		putchar('\n');
	}
	Terminate(&q);
	return 0;
}