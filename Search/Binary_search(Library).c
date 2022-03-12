#include <stdio.h>
#include <stdlib.h>

/* 요소의 개수가 n인 배열 arr에서 key와 일치하는 요소를 이진 검색(라이브러리 사용) */
/* 정수를 비교하는 함수(오름차순) */
int int_cmp(const int *a, const int *b) {
	if (*a > *b)
		return 1;
	else if (*a < *b)
		return -1;
	else
		return 0;
}
int main(void) {
	int n, key;		/* 배열크기, 검색할 요소 */
	int* arr;			/* 데이터를 가지고 있는 배열 */
	int* p;				/* 검색한 요소에 대한 포인터 */

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
	p = bsearch(&key, arr, n, sizeof(int), (int(*)(const void*, const void*))int_cmp);

	if (p == NULL)
		printf("존재하지않는 데이터입니다.\n");
	else
		printf("%d는 arr[%d]에 존재합니다.\n", key, (int)(p - arr));

	free(arr);
	return 0;
}