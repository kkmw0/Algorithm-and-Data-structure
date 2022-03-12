#include <stdio.h>
#include <stdlib.h>

/* qsort 함수를 사용하여 정수 배열을 오름차순으로 정렬 */
/* 정수를 비교하는 함수(오름차순) */
/* 같은 키 값을 가지고 있는 데이터가 2개 이상인 경우 정렬 전후의 데이터가 같은 순서를 유지하지않는다.(안정적 X)*/
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

	puts("퀵 정렬(라이브러리 사용)");
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
	qsort(x, n, sizeof(int), (int(*)(const void*, const void*))int_cmp);

	puts("오름차순으로 정렬했습니다.");
	for (int i = 0; i < n; i++)
		printf("x[%d] = %d\n", i, x[i]);
	free(x);

	return 0;
}