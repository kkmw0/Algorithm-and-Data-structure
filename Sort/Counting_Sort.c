#include <stdio.h>
#include <stdlib.h>

/* ���� ����(�迭��Ҹ� �ǳʶ��� �ʰ� ������� ��ĵ�ϹǷ� ������) */
/* �������� ��, ��ȯ �۾��� ���� �ſ� ���� ���� */
/* ������ ��������ǥ�� �ʿ��ϹǷ� �������� �ּڰ��� �ִ��� �̸� �˰� �־�ߵ� */
int Counting_Sort(int x[], int n, int max) {
	int i;
	int* f ;		/* ���������� ���� ��������ǥ�� �����ϴ� �迭 */
	int* b;			/* ������ �迭�� �ӽ� �����ϴ� �迭 */

	f = calloc(max + 1, sizeof(int));
	b = calloc(n, sizeof(int));
	if (f == NULL || b == NULL)
		return -1;

	for (i = 0; i < n; i++) f[x[i]]++;						/* ��������ǥ ����(�� ������ �ش��ϴ� �л� ���� ��Ÿ��) */
	for (i = 1; i <= max; i++)  f[i] += f[i - 1];		/* ������������ǥ ����(0������ n������ ����� �л��� �ִ��� ������ ���� ��Ÿ��) */
	for (i = n - 1; i >= 0; i--) b[--f[x[i]]] = x[i];		/* �����迭 ����(�迭�� �� ��ڰ��� ������������ǥ�� �����Ͽ� ������ ��ģ �迭�� ����) */
	for (i = 0; i < n; i++) x[i] = b[i];					/* �۾��迭�� �����迭�� �����Ͽ� ������ ��ħ */
}

int main(void) {
	int n;
	int* x;
	const int max = 100;	 /* ���� ū �� */

	puts("���� ����");
	printf("��� ���� : ");
	scanf_s("%d", &n);

	x = calloc(n, sizeof(int));
	if (x == NULL)
		return -1;

	printf("0 ~ %d������ ������ �Է��ϼ���.\n", max);
	for (int i = 0; i < n; i++) {
		do {
			printf("x[%d] : ", i);
			scanf_s("%d", &x[i]);
		} while (x[i] < 0 || x[i] > max);
	}
	putchar('\n');
	Counting_Sort(x, n, max);

	puts("������������ �����߽��ϴ�.");
	for (int i = 0; i < n; i++)
		printf("x[%d] = %d\n", i, x[i]);
	free(x);

	return 0;
}