#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"
int main(void) {
	IntStack s;
	if (Initialize(&s, 64) == -1) {
		puts("���� ���� ����.");
		return 1;
	}

	while (1) {
		int menu, x, key, idx;
		printf("���� ������ �� : %d / %d\n", Size(&s), Capacity(&s));
		printf("(1)Ǫ��  (2)��  (3)��ũ  (4)���  (5)�˻�  (0)���� : ");
		scanf_s("%d", &menu);

		if (menu == 0) break;
		switch (menu)
		{
		case 1: /* Ǫ�� */
			printf("������ : ");
			scanf_s("%d", &x);

			if (Push(&s, x) == -1)
				puts("���� : Ǫ�ÿ� �����Ͽ����ϴ�.");
			break;

		case 2: /* �� */
			if (Pop(&s, &x) == -1)
				puts("���� : �˿� �����Ͽ����ϴ�.");
			else
				printf("�� �����ʹ� %d�Դϴ�.\n", x);
			break;

		case 3: /* ��ũ */
			if(Peek(&s, &x) == -1)
				puts("���� : ��ũ�� �����Ͽ����ϴ�.");
			else
				printf("��ũ �����ʹ� %d�Դϴ�.\n", x);
			break;

		case 4: /* ��� */
			Print(&s);
			break;

		case 5: /* �˻� */
			printf("�˻��� ������ �Է� : ");
			scanf_s("%d", &key);

			idx = Search(&s, key);
			if (idx  == -1)
				printf("%d�� ���ÿ� ���������ʽ��ϴ�.\n", key);
			else {
				printf("�˻�����!\n");
				printf("%d�� stk[%d]�� �ֽ��ϴ�.\n", key, idx);
			}
		}
		putchar('\n');
	}
	Terminate(&s);
	return 0;
}