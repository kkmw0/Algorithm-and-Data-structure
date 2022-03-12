#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

/* �迭�� �ʱ갪�̳� �ǹ��� ���ÿ� ���� �ð� ���⵵�� �����ϴ� ��찡 �����Ѵ�. */
/* �ּ��� ��� ����� ������ 2�� �ŵ������� ��, log n���� �񱳸� ��Ұ��� n����ŭ �ݺ��ϹǷ� O(n log n)�� �ȴ�. */
/* �־��� ���(�����ϰ��� �ϴ� �迭�� ���������̳� ������������ ���ĵ� ���) */
/* ����� ������ 2�� �ŵ������� �� n���� �񱳸� ��Ұ��� n����ŭ �ݺ��ϹǷ� O(n^2)�� �ȴ�. */
/* ���� Ű ���� ������ �ִ� �����Ͱ� 2�� �̻��� ��� ���� ������ �����Ͱ� ���� ������ ���������ʴ´�.(������ X)*/

/* �迭���� ù ���, �߰� ���, �� ��Ҹ� ũ������� ���� �� �߰� ����� �ε����� ���� */
int Sort_3Element(int x[], int a, int b, int c) {
	if (x[a] > x[b]) swap(int, x[a], x[b]);
	if (x[b] > x[c]) swap(int, x[b], x[c]);
	if (x[a] > x[b]) swap(int, x[a], x[b]);
	return b;
}

/* �� ����(������� ���) */
void Quick_Sort(int x[], int left, int right) {
	int pl = left;						/* ���� Ŀ�� */
	int pr = right;					/* ������ Ŀ�� */

	int m = Sort_3Element(x, pl, (pl + pr) / 2, pr);	/* ��� �ε��� */
	int pivot = x[m];				/* ��� ��� */

	swap(int, x[m], x[right - 1]);	/* �߰���ҿ� ������ �ι�° ��Ҹ� ��ȯ(��ĵ ��Ҹ� 3���� ���� �� ����) */
	/* �ι�°��Һ��� ������ �ι�°���� ��ĵ */
	pl++;
	pr -= 2;

	/* pivot�� �������� �迭�� ���� */
	do {
		while (x[pl] < pivot) pl++;
		while (x[pr] > pivot) pr--;
		if (pl <= pr) {
			swap(int, x[pl], x[pr]);
			pl++;
			pr--;
		}
	} while (pl <= pr);

	/* ����� ������ ���� �׷��� ���� ���� ���ÿ� ���̴� �������� �ִ� ������ ���� */
	if (pr - left < right - pl) {
		swap(int, pl, left);
		swap(int, pr, right);
	}

	/* ���ȣ���Ͽ� ��Ұ����� 1���� �� ������ �׷��� ���� */
	if (left < pr) Quick_Sort(x, left, pr);
	if (pl < right) Quick_Sort(x, pl, right);
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
	Quick_Sort(x, 0, n - 1);

	puts("������������ �����߽��ϴ�.");
	for (int i = 0; i < n; i++)
		printf("x[%d] = %d\n", i, x[i]);
	free(x);

	return 0;
}