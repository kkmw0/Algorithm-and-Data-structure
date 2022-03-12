#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

/* 힙정렬은 가장 큰 요소값을 선택하는 시간복잡도 O(1)로 줄일 수 있다. */
/* 하지만 힙 정렬에서 다시 힙으로 만드는 작업의 시간 복잡도는 O(log n)이다. */
/* 따라서 힙으로 만드는 작업을 요소의 개수만큼 반복하므로 전체 시간복잡도는 O(n log n)이 된다. */

/* x[left] ~ x[right]를 힙으로 만드는 함수 */
static void downHeap(int x[], int left, int right) {
	int tmp = x[left];	/* 루트 값 */
	int child;
	int parent;

	for (parent = left; parent < (right + 1) / 2; parent = child) {
		int cl = parent * 2 + 1;		/* 왼쪽자식 */
		int cr = cl + 1;					/* 오른쪽 자식 */
		child = (cr <= right && x[cr] > x[cl]) ? cr : cl;	/* 더 큰 값을 선택 */
		
		if (tmp >= x[child])
			break;
		x[parent] = x[child];
	}
	x[parent] = tmp;
}

/* 힙 정렬 */
int Heap_Sort(int x[], int n) {
	/* downHeap 함수를 사용하여 배열 x를 힙으로 만듬 */
	for (int i = (n - 1) / 2; i >= 0; i--)
		downHeap(x, i, n - 1);

	/* 가장 큰 값(루트)를 배열의 마지막 요소와 바꾸고 배열의 나머지를 다시 힙으로 만듬 */
	for (int i = n - 1; i > 0; i--) {
		swap(int, x[0], x[i]);
		downHeap(x, 0, i - 1);
	}
}

int main(void) {
	int n;
	int* x;

	puts("힙 정렬");
	printf("요소 개수 : ");
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

	puts("오름차순으로 정렬했습니다.");
	for (int i = 0; i < n; i++)
		printf("x[%d] = %d\n", i, x[i]);
	free(x);

	return 0;
}