#include <stdio.h>
#include <stdlib.h>

static int* buff;		/* ������ ����� �ӽ÷� �����ϴ� �迭 */

/* ���� ����(���� ������ �ִ� ��Ҹ� ��ȯ�ϴ� ���� �ƴϹǷ� ������) */
/* �迭 ������ �ð� ���⵵�� O(n)�̰�, �������� ��� ������ n����� �ϸ� */
/* ���� ������ �ܰ�� log n��ŭ �ʿ��ϹǷ� ��ü �ð� ���⵵�� O(n log n)�� �ȴ�.*/
static void __Merge_Sort(int x[], int left, int right) {
	if (left < right) {
		int center = (left + right) / 2;
		int idx = 0;
		int i = 0;
		int j = 0;
		int k = left;

		__Merge_Sort(x, left, center);			/* �պκп� ���� ���� ���� */
		__Merge_Sort(x, center + 1, right);		/* �޺κп� ���� ���� ���� */
		
		/* �迭 �պκ��� �ӽù迭(buff)�� ���� */
		for (i = left; i <= center; i++)
			buff[idx++] = x[i];
		/* �迭 x�� �޺κа� �ӽù迭(buff)�� �迭x�� ���� */
		while (i <= right && j < idx)
			x[k++] = (buff[j] <= x[i]) ? buff[j++] : x[i++];
		/* �ӽù迭(buff)�� ������ ��Ҹ� �迭 x�� ���� */
		while (j < idx)
			x[k++] = buff[j++];
	}
}

int Merge_Sort(int x[], int n) {
	if ((buff = calloc(n, sizeof(int))) == NULL)
		return -1;

	__Merge_Sort(x, 0, n - 1);	/* �迭 ��ü�� �������� */
	free(buff);
	return 0;
}

int main(void) {
	int n;
	int* x;

	puts("���� ����");
	printf("��� ���� : ");
	scanf_s("%d", &n);

	x = calloc(n, sizeof(int));
	if (x == NULL)
		return -1;

	for (int i = 0; i < n; i++) {
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}
	putchar('\n');
	Merge_Sort(x, n);

	puts("������������ �����߽��ϴ�.");
	for (int i = 0; i < n; i++)
		printf("x[%d] = %d\n", i, x[i]);
	free(x);

	return 0;
}