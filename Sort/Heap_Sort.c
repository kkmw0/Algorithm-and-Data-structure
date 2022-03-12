#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

/* �������� ���� ū ��Ұ��� �����ϴ� �ð����⵵ O(1)�� ���� �� �ִ�. */
/* ������ �� ���Ŀ��� �ٽ� ������ ����� �۾��� �ð� ���⵵�� O(log n)�̴�. */
/* ���� ������ ����� �۾��� ����� ������ŭ �ݺ��ϹǷ� ��ü �ð����⵵�� O(n log n)�� �ȴ�. */

/* x[left] ~ x[right]�� ������ ����� �Լ� */
static void downHeap(int x[], int left, int right) {
	int tmp = x[left];	/* ��Ʈ �� */
	int child;
	int parent;

	for (parent = left; parent < (right + 1) / 2; parent = child) {
		int cl = parent * 2 + 1;		/* �����ڽ� */
		int cr = cl + 1;					/* ������ �ڽ� */
		child = (cr <= right && x[cr] > x[cl]) ? cr : cl;	/* �� ū ���� ���� */
		
		if (tmp >= x[child])
			break;
		x[parent] = x[child];
	}
	x[parent] = tmp;
}

/* �� ���� */
int Heap_Sort(int x[], int n) {
	/* downHeap �Լ��� ����Ͽ� �迭 x�� ������ ���� */
	for (int i = (n - 1) / 2; i >= 0; i--)
		downHeap(x, i, n - 1);

	/* ���� ū ��(��Ʈ)�� �迭�� ������ ��ҿ� �ٲٰ� �迭�� �������� �ٽ� ������ ���� */
	for (int i = n - 1; i > 0; i--) {
		swap(int, x[0], x[i]);
		downHeap(x, 0, i - 1);
	}
}

int main(void) {
	int n;
	int* x;

	puts("�� ����");
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
	Heap_Sort(x, n);

	puts("������������ �����߽��ϴ�.");
	for (int i = 0; i < n; i++)
		printf("x[%d] = %d\n", i, x[i]);
	free(x);

	return 0;
}