#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

/* 배열의 초깃값이나 피벗의 선택에 따라 시간 복잡도가 증가하는 경우가 존재한다. */
/* 최선의 경우 요소의 개수가 2의 거듭제곱일 때, log n번의 비교를 요소개수 n번만큼 반복하므로 O(n log n)이 된다. */
/* 최악의 경우(정렬하고자 하는 배열이 오름차순이나 내림차순으로 정렬된 경우) */
/* 요소의 개수가 2의 거듭제곱일 때 n번의 비교를 요소개수 n번만큼 반복하므로 O(n^2)이 된다. */
/* 같은 키 값을 가지고 있는 데이터가 2개 이상인 경우 정렬 전후의 데이터가 같은 순서를 유지하지않는다.(안정적 X)*/

/* 배열에서 첫 요소, 중간 요소, 끝 요소를 크기순으로 정렬 후 중간 요소의 인덱스를 리턴 */
int Sort_3Element(int x[], int a, int b, int c) {
	if (x[a] > x[b]) swap(int, x[a], x[b]);
	if (x[b] > x[c]) swap(int, x[b], x[c]);
	if (x[a] > x[b]) swap(int, x[a], x[b]);
	return b;
}

/* 퀵 정렬(스택사용) */
void Quick_Sort(int x[], int left, int right) {
	IntStack lstack;		/* 나눌 첫번째 요소 인덱스의 스택 */
	IntStack rstack;		/* 나눌 마지막 요소 인덱스의 스택 */

	/* 스택 생성 */
	Initialize(&lstack, right - left + 1);
	Initialize(&rstack, right - left + 1);

	Push(&lstack, left);
	Push(&rstack, right);

	while (!isEmpty(&lstack)) {
		// 정렬할 배열의 범위를 정함
		int pl = (Pop(&lstack, &left), left);			/* 왼쪽 커서 */
		int pr = (Pop(&rstack, &right), right);		/* 오른쪽 커서 */

		int m = Sort_3Element(x, pl, (pl + pr) / 2, pr);	/* 가운데 인덱스 */
		int pivot = x[m];				/* 가운데 요소 */

		swap(int, x[m], x[right - 1]);	/* 중간요소와 끝에서 두번째 요소를 교환(스캔 요소를 3개씩 줄일 수 있음) */
		/* 두번째요소부터 끝에서 두번째까지 스캔 */
		pl++;
		pr -= 2;

		do {
			while (x[pl] < pivot) pl++;
			while (x[pr] > pivot) pr--;
			if (pl <= pr) {
				swap(int, x[pl], x[pr]);
				pl++;
				pr--;
			}
		} while (pl <= pr);

		/* 요소의 개수가 적은 그룹을 먼저 나눠 스택에 쌓이는 데이터의 최대 개수를 줄임 */
		if (pr - left < right - pl) {
			swap(int, pl, left);
			swap(int, pr, right);
		}

		/* 왼쪽 그룹 범위의 인덱스를 푸시 */
		if (left < pr) {
			Push(&lstack, left);
			Push(&rstack, pr);
		}
		/* 오른쪽 그룹 범위의 인덱스를 푸시 */
		if (pl < right) {
			Push(&lstack, pl);
			Push(&rstack, right);
		}
	}
	Terminate(&lstack);
	Terminate(&rstack);
}

int main(void) {
	int n;
	int* x;

	puts("퀵 정렬");
	printf("요소 개수 : ");
	scanf_s("%d", &n);
	x = calloc(n, sizeof(int));

	for (int i = 0; i < n; i++) {
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}
	putchar('\n');
	Quick_Sort(x, 0, n - 1);

	puts("오름차순으로 정렬했습니다.");
	for (int i = 0; i < n; i++)
		printf("x[%d] = %d\n", i, x[i]);
	free(x);

	return 0;
}