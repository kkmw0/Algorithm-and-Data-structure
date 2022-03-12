#include <stdio.h>
#include <stdlib.h>

/* 셸 정렬(멀리 떨어져 있는 요소를 교환하므로 안정적 X) */
/* 단순 삽입 정렬의 장점을 살리고, 단점을 보완하여 좀 더 빠르게 동작하는 알고리즘 */
/* 데이터를 나누는 값에 따라 성능이 달라진다. 최악의 경우 O(n^2), 평균 O(n^1.25 ~ n^1.5)*/
/* 전체에서 2를 나누는 것보다 3으로 나누고 1을 더하는 경우가 더 빠르다고 알려져있다. */
void Shell_Sort(int x[], int n) {
	int i, j, h;

	for (h = 1; h < n / 9; h = h * 3 + 1);		/* h의 초기값을 계산(h값이 크면  효과가 없으므로 요소개수 / 9를 함) */
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

	puts("셸 정렬");
	printf("요소 개수 : ");
	scanf_s("%d", &n);
	x = calloc(n, sizeof(int));

	for (int i = 0; i < n; i++) {
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}
	putchar('\n');
	Shell_Sort(x, n);

	puts("오름차순으로 정렬했습니다.");
	for (int i = 0; i < n; i++)
		printf("x[%d] = %d\n", i, x[i]);
	free(x);

	return 0;
}