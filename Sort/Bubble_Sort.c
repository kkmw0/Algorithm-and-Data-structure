#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while(0)

/* ��ĵ ������ ������ ���� ����*/
void Bubble_Sort(int x[], int n) {
	int k = 0;			/* a[k]���� ������ ��Ҵ� ������ ��ģ ���� */

	while (k < n - 1) {
		int last = n - 1;						/* ���������� ��ȯ�� ������ ��ġ�� ���� */
		for (int i = n - 1; i > k; j--) {
			if (x[i - 1] > x[i]) {
				swap(int, x[i - 1], x[i]);
				last = i;
			}
		}
		k = last;
	}
}

int main(void) {
	int n;
	int* x;

	puts("���� ����");
	printf("��� ���� : ");
	scanf_s("%d",&n);
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