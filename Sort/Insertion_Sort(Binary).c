#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 이진 삽입 정렬(이미 정렬된 요소를 이진 탐색하여 삽입위치를 정함) */
void Insertion_Sort(int x[], int n) {
	int i, j;
	for (i = 1; i < n; i++) {
		int key = x[i];
		int pl = 0;			/* 검색 범위의 첫번째 인덱스 */
		int pr = i - 1;		/* 검색 범위의 마지막 인덱스 */
		int pc;					/* 검색 범위의 가운데 인덱스 */
		int pd;				/* 삽입하는 위치의 인덱스 */

		do {
			pc = (pl + pr) / 2;
			if (x[pc] == key)
				break;
			else if (x[pc] < key)
				pl = pc + 1;
			else
				pr = pc - 1;
		} while (pl <= pr);
		pd = (pl <= pr) ? pc + 1 : pr + 1;

		/* 요소를 하나씩 뒤쪽으로 미는 방법 */
//		for (j = i; j > pd; j--) {
//			x[j] = x[j - 1];
//		}
//		x[pd] = key;

		/* memmove함수를 이용하여 비용을 절약하는 방법 */
		memmove(&x[pd + 1], &x[pd], (i - pd) * sizeof(int));
		x[pd] = key;
	}
}

int main(void) {
	int n;
	int* x;

	puts("이진 삽입 정렬");
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