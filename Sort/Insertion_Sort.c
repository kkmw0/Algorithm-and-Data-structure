#include <stdio.h>
#include <stdlib.h>

/* 삽입 정렬 */
void Insertion_Sort(int x[], int n) {
	int i, j, tmp;
	for (i = 1; i < n; i++) {
		tmp = x[i];
		for (j = i; j > 0 && x[j - 1] > tmp; j--) {
			x[j] = x[j - 1];
		}
		x[j] = tmp;
	}
}

int main(void) {
	int n;
	int* x;

	puts("삽입 정렬");
	printf("요소 개수 : ");
	scanf_s("%d", &n);
	x = calloc(n, sizeof(int));

	for (int i = 0; i < n; i++) {
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}
	putchar('\n');
	Insertion_Sort(x, n);

	puts("오름차순으로 정렬했습니다.");
	for (int i = 0; i < n; i++)
		printf("x[%d] = %d\n", i, x[i]);
	free(x);

	return 0;
}