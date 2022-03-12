#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ���� ���� ����(�̹� ���ĵ� ��Ҹ� ���� Ž���Ͽ� ������ġ�� ����) */
void Insertion_Sort(int x[], int n) {
	int i, j;
	for (i = 1; i < n; i++) {
		int key = x[i];
		int pl = 0;			/* �˻� ������ ù��° �ε��� */
		int pr = i - 1;		/* �˻� ������ ������ �ε��� */
		int pc;					/* �˻� ������ ��� �ε��� */
		int pd;				/* �����ϴ� ��ġ�� �ε��� */

		do {
			pc = (pl + pr) / 2;
			if (x[pc] == key)
				break;
			else if (x[pc] < key)
				pl = pc + 1;
			else
				pr = pc - 1;
		} while (pl <= pr);
		pd = (pl <= pr) ? pc + 1 : pr + 1;

		/* ��Ҹ� �ϳ��� �������� �̴� ��� */
//		for (j = i; j > pd; j--) {
//			x[j] = x[j - 1];
//		}
//		x[pd] = key;

		/* memmove�Լ��� �̿��Ͽ� ����� �����ϴ� ��� */
		memmove(&x[pd + 1], &x[pd], (i - pd) * sizeof(int));
		x[pd] = key;
	}
}

int main(void) {
	int n;
	int* x;

	puts("���� ���� ����");
	printf("��� ���� : ");
	scanf_s("%d", &n);
	x = calloc(n, sizeof(int));

	for (int i = 0; i < n; i++) {
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}
	putchar('\n');
	Insertion_Sort(x, n);

	puts("������������ �����߽��ϴ�.");
	for (int i = 0; i < n; i++)
		printf("x[%d] = %d\n", i, x[i]);
	free(x);

	return 0;
}