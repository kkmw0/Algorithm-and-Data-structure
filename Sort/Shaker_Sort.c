#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while(0)

/* ����� ���� ����(����Ŀ ����) */
void Bubble_Sort(int x[], int n) {
	int left = 0;
	int right = n - 1;
	int last = right;

	while (left < right) {
		for (int j = right; j > left; j--) {			/* Ȧ�� ��° �н������� ���� ���� ��Ҹ� �� ������ �ű� */
			if (x[j - 1] > x[j]) {
				swap(int, x[j - 1], x[j]);
				last = j;
			}
		}
		left = last;

		for (int j = left; j < right; j++) {			/* ¦�� ��° �н������� ���� ū ��Ҹ� �� �ڷ� �ű� */
			if (x[j] > x[j + 1]) {
				swap(int, x[j], x[j + 1]);
				last = j;
			}
		}
		right = last;
	}
}

int main(void) {
	int n;
	int* x;

	puts("����Ŀ ����");
	printf("��� ���� : ");
	scanf_s("%d", &n);
	x = calloc(n, sizeof(int));

	for (int i = 0; i < n; i++) {
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}
	putchar('\n');
	Bubble_Sort(x, n);

	puts("������������ �����߽��ϴ�.");
	for (int i = 0; i < n; i++)
		printf("x[%d] = %d\n", i, x[i]);
	free(x);

	return 0;
}