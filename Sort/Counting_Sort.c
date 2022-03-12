#include <stdio.h>
#include <stdlib.h>

/* 도수 정렬(배열요소를 건너뛰지 않고 순서대로 스캔하므로 안정적) */
/* 데이터의 비교, 교환 작업이 없어 매우 빠른 정렬 */
/* 하지만 도수분포표가 필요하므로 데이터의 최솟값과 최댓값을 미리 알고 있어야됨 */
int Counting_Sort(int x[], int n, int max) {
	int i;
	int* f ;		/* 도수분포와 누적 도수분포표를 저장하는 배열 */
	int* b;			/* 정렬한 배열을 임시 저장하는 배열 */

	f = calloc(max + 1, sizeof(int));
	b = calloc(n, sizeof(int));
	if (f == NULL || b == NULL)
		return -1;

	for (i = 0; i < n; i++) f[x[i]]++;						/* 도수분포표 생성(각 점수에 해당하는 학생 수를 나타냄) */
	for (i = 1; i <= max; i++)  f[i] += f[i - 1];		/* 누적도수분포표 생성(0점부터 n점까지 몇명의 학생이 있는지 누적된 값을 나타냄) */
	for (i = n - 1; i >= 0; i--) b[--f[x[i]]] = x[i];		/* 목적배열 생성(배열의 각 요솟값과 누적도수분포표를 대조하여 정렬을 마친 배열을 생성) */
	for (i = 0; i < n; i++) x[i] = b[i];					/* 작업배열을 기존배열에 복사하여 정렬을 마침 */
}

int main(void) {
	int n;
	int* x;
	const int max = 100;	 /* 가장 큰 값 */

	puts("도수 정렬");
	printf("요소 개수 : ");
	scanf_s("%d", &n);

	x = calloc(n, sizeof(int));
	if (x == NULL)
		return -1;

	printf("0 ~ %d사이의 정수를 입력하세요.\n", max);
	for (int i = 0; i < n; i++) {
		do {
			printf("x[%d] : ", i);
			scanf_s("%d", &x[i]);
		} while (x[i] < 0 || x[i] > max);
	}
	putchar('\n');
	Counting_Sort(x, n, max);

	puts("오름차순으로 정렬했습니다.");
	for (int i = 0; i < n; i++)
		printf("x[%d] = %d\n", i, x[i]);
	free(x);

	return 0;
}