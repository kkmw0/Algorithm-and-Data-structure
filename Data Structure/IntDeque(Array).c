#include <stdio.h>
#include <stdlib.h>
#include "IntDeque.h"
int main(void) {
	IntDeque d;
	if (Initialize(&d, 64) == -1) {
		puts("ť ���� ����.");
		return 1;
	}

	while (1) {
		int menu, x, key, idx;
		printf("���� ������ �� : %d / %d\n", Size(&d), Capacity(&d));
		printf("(1)Push_front  (2)Push_rear  (3)Pop_front  (4)Pop_rear  (5)Peek_front  (6)Peek_rear\n");
		printf("(7)Search      (8)Print      (9)Reset      (0)Exit : ");
		scanf_s("%d", &menu);

		if (menu == 0) break;
		switch (menu)
		{
		case 1: /* Push_front */
			printf("������ : ");
			scanf_s("%d", &x);

			if (Push_front(&d, x) == -1)
				puts("���� : Push_front�� �����Ͽ����ϴ�.");
			break;

		case 2: /* Push_rear */
			printf("������ : ");
			scanf_s("%d", &x);

			if (Push_rear(&d, x) == -1)
				puts("���� : Push_rear�� �����Ͽ����ϴ�.");
			break;

		case 3: /* Pop_front */
			if (Pop_front(&d, &x) == -1)
				puts("���� : Pop_front�� �����Ͽ����ϴ�.");
			else
				printf("�� �����ʹ� %d�Դϴ�.\n", x);
			break;

		case 4: /* Pop_rear */
			if (Pop_rear(&d, &x) == -1)
				puts("���� : Pop_rear�� �����Ͽ����ϴ�.");
			else
				printf("�� �����ʹ� %d�Դϴ�.\n", x);
			break;

		case 5: /* Peek_front */
			if (Peek_front(&d, &x) == -1)
				puts("���� : Peek_front�� �����Ͽ����ϴ�.");
			else
				printf("��ũ �����ʹ� %d�Դϴ�.\n", x);
			break;

		case 6: /* Peek_rear */
			if (Peek_rear(&d, &x) == -1)
				puts("���� : Peek_rear�� �����Ͽ����ϴ�.");
			else
				printf("��ũ �����ʹ� %d�Դϴ�.\n", x);
			break;

		case 7: /* Search */
			printf("�˻��� ������ �Է� : ");
			scanf_s("%d", &key);

			idx = Search(&d, key);
			if (idx == -1)
				printf("%d�� ���� ���������ʽ��ϴ�.\n", key);
			else {
				printf("�˻�����!\n");
				printf("%d�� deque[%d]�� �ֽ��ϴ�.\n", key, idx);
			}
			break;

		case 8: /* Print */
			Print(&d);
			break;

		case 9: /* Clear */
			Clear(&d);
		}
		putchar('\n');
	}
	Terminate(&d);
	return 0;
}