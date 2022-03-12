#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while(0)

/* 스캔 범위를 제한한 버블 정렬*/
void Bubble_Sort(int x[], int n) {
	int k = 0;			/* a[k]보다 앞쪽의 요소는 정렬을 마친 상태 */

	while (k < n - 1) {
		int last = n - 1;						/* 마지막으로 교환을 수행한 위치를 저장 */
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

	puts("버블 정렬");
	printf("요소 개수 : ");
	scanf_s("%d",&n);
	x = calloc(n, sizeof(int));

	for (int i = 0; i < n; i++) {
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}
	putchar('\n');
	Bubble_Sort(x, n);

	puts("오름차순으로 정렬했습니다.");
	for (int i = 0; i < n; i++)
		printf("x[%d] = %d\n", i, x[i]);
	free(x);

	return 0;
}