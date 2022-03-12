#include <stdio.h>
#include <stdlib.h>

static int* buff;		/* 병합한 결과를 임시로 저장하는 배열 */

/* 병합 정렬(서로 떨어져 있는 요소를 교환하는 것이 아니므로 안정적) */
/* 배열 병합의 시간 복잡도는 O(n)이고, 데이터의 요소 개수가 n개라고 하면 */
/* 병합 정렬의 단계는 log n만큼 필요하므로 전체 시간 복잡도는 O(n log n)이 된다.*/
static void __Merge_Sort(int x[], int left, int right) {
	if (left < right) {
		int center = (left + right) / 2;
		int idx = 0;
		int i = 0;
		int j = 0;
		int k = left;

		__Merge_Sort(x, left, center);			/* 앞부분에 대한 병합 정렬 */
		__Merge_Sort(x, center + 1, right);		/* 뒷부분에 대한 병합 정렬 */
		
		/* 배열 앞부분을 임시배열(buff)에 복사 */
		for (i = left; i <= center; i++)
			buff[idx++] = x[i];
		/* 배열 x의 뒷부분과 임시배열(buff)을 배열x에 병합 */
		while (i <= right && j < idx)
			x[k++] = (buff[j] <= x[i]) ? buff[j++] : x[i++];
		/* 임시배열(buff)의 나머지 요소를 배열 x에 복사 */
		while (j < idx)
			x[k++] = buff[j++];
	}
}

int Merge_Sort(int x[], int n) {
	if ((buff = calloc(n, sizeof(int))) == NULL)
		return -1;

	__Merge_Sort(x, 0, n - 1);	/* 배열 전체를 병합정렬 */
	free(buff);
	return 0;
}

int main(void) {
	int n;
	int* x;

	puts("병합 정렬");
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
	Merge_Sort(x, n);

	puts("오름차순으로 정렬했습니다.");
	for (int i = 0; i < n; i++)
		printf("x[%d] = %d\n", i, x[i]);
	free(x);

	return 0;
}