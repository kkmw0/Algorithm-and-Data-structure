#include <stdio.h>
#include <stdlib.h>

/* qsort �Լ��� ����Ͽ� ���� �迭�� ������������ ���� */
/* ������ ���ϴ� �Լ�(��������) */
/* ���� Ű ���� ������ �ִ� �����Ͱ� 2�� �̻��� ��� ���� ������ �����Ͱ� ���� ������ ���������ʴ´�.(������ X)*/
int int_cmp(const int* a, const int* b) {
	if (*a > *b)
		return 1;
	else if (*a < *b)
		return -1;
	else
		return 0;
}
int main(void) {
	int n;
	int* x;

	puts("�� ����(���̺귯�� ���)");
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
	qsort(x, n, sizeof(int), (int(*)(const void*, const void*))int_cmp);

	puts("������������ �����߽��ϴ�.");
	for (int i = 0; i < n; i++)
		printf("x[%d] = %d\n", i, x[i]);
	free(x);

	return 0;
}