#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while(0)

/* 선택 정렬 */
void Selection_Sort(int x[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			if (x[min] > x[j])
				min = j;
		}
		swap(int, x[i], x[min]);
	}
}

int main(void) {
	int n;
	int* x;

	puts("선택 정렬");
	printf("요소 개수 : ");
	scanf_s("%d", &n);
	x = calloc(n, sizeof(int));

	for (int i = 0; i < n; i++) {
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}
	putchar('\n');
	Selection_Sort(x, n);

	puts("오름차순으로 정렬했습니다.");
	for (int i = 0; i < n; i++)
		printf("x[%d] = %d\n", i, x[i]);
	free(x);

	return 0;
}