#include <stdio.h>
#include <stdlib.h>

/* 요소의 개수가 n인 배열 arr에서 key와 일치하는 요소를 이진 검색 */
int binary_search(int arr[], int n, int key) {
	int pl = 0;		/* 검색 범위의 맨 왼쪽 인덱스 */
	int pr = n - 1;	/* 검색 범위의 맨 오른쪽 인덱스 */
	int pc;				/* 검색 범위의 가운데 인덱스 */

	do {
		pc = (pl + pr) / 2;
		if (arr[pc] == key)		/* 검색 성공 */
			return pc;
		else if (arr[pc] > key)
			pr = pc - 1;
		else
			pl = pc + 1;
	} while (pl <= pr);
	return -1;					/* 검색 실패 */
}
int main(void) {
	int n, key;		/* 배열크기, 검색할 요소 */
	int idx;			/* 검색한 요소가 존재하는 배열의 인덱스 */
	int* arr;			/* 데이터를 가지고 있는 배열 */

	printf("요소 개수 : ");
	scanf_s("%d", &n);

	/* 동적할당 */
	arr = calloc(n, sizeof(int));
	if (arr == NULL)
		return -1;

	/* 데이터 입력*/
	printf("오름차순으로 입력하세요\n");
	printf("arr[0] : ");
	scanf_s("%d", &arr[0]);
	for (int i = 1; i < n; i++) {
		do {
			printf("arr[%d] : ", i);
			scanf_s("%d", &arr[i]);
		} while (arr[i] < arr[i - 1]);
	}

	/* 검색 */
	printf("검색할 데이터 : ");
	scanf_s("%d", &key);
	idx = binary_search(arr, n, key);

	if (idx == -1)
		printf("존재하지않는 데이터입니다.\n");
	else
		printf("%d는 arr[%d]에 존재합니다.\n", key, idx);

	free(arr);
	return 0;
}