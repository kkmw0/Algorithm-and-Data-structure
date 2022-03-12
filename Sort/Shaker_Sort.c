#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while(0)

/* 양방향 버블 정렬(셰이커 정렬) */
void Bubble_Sort(int x[], int n) {
	int left = 0;
	int right = n - 1;
	int last = right;

	while (left < right) {
		for (int j = right; j > left; j--) {			/* 홀수 번째 패스에서는 가장 작은 요소를 맨 앞으로 옮김 */
			if (x[j - 1] > x[j]) {
				swap(int, x[j - 1], x[j]);
				last = j;
			}
		}
		left = last;

		for (int j = left; j < right; j++) {			/* 짝수 번째 패스에서는 가장 큰 요소를 맨 뒤로 옮김 */
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

	puts("셰이커 정렬");
	printf("요소 개수 : ");
	scanf_s("%d", &n);
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