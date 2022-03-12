#include <stdio.h>
#include <stdlib.h>

/* �� ����(�ָ� ������ �ִ� ��Ҹ� ��ȯ�ϹǷ� ������ X) */
/* �ܼ� ���� ������ ������ �츮��, ������ �����Ͽ� �� �� ������ �����ϴ� �˰��� */
/* �����͸� ������ ���� ���� ������ �޶�����. �־��� ��� O(n^2), ��� O(n^1.25 ~ n^1.5)*/
/* ��ü���� 2�� ������ �ͺ��� 3���� ������ 1�� ���ϴ� ��찡 �� �����ٰ� �˷����ִ�. */
void Shell_Sort(int x[], int n) {
	int i, j, h;

	for (h = 1; h < n / 9; h = h * 3 + 1);		/* h�� �ʱⰪ�� ���(h���� ũ��  ȿ���� �����Ƿ� ��Ұ��� / 9�� ��) */
	for (; h > 0; h /= 3) {
		for (i = h; i < n; i++) {
			int tmp = x[i];
			for (j = i - h; j >= 0 && x[j] > tmp; j -= h) {
				x[j + h] = x[j];
			}
			x[j + h] = tmp;
		}
	}
}

int main(void) {
	int n;
	int* x;

	puts("�� ����");
	printf("��� ���� : ");
	scanf_s("%d", &n);
	x = calloc(n, sizeof(int));

	for (int i = 0; i < n; i++) {
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}
	putchar('\n');
	Shell_Sort(x, n);

	puts("������������ �����߽��ϴ�.");
	for (int i = 0; i < n; i++)
		printf("x[%d] = %d\n", i, x[i]);
	free(x);

	return 0;
}