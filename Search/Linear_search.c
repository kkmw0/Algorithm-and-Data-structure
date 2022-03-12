#include <stdio.h>
#include <stdlib.h>

/* 요소의 개수가 n인 배열 arr에서 key와 일치하는 요소를 선형 검색 */
int linear_search(const int arr[], int n, int key) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == key)
			return i;
	}
	return -1;
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
	for (int i = 0; i < n; i++) {
		printf("arr[%d] : ", i);
		scanf_s("%d", &arr[i]);
	}

	/* 검색 */
	printf("검색할 데이터 : ");
	scanf_s("%d", &key);
	idx = linear_search(arr, n, key);

	if (idx == -1)
		printf("존재하지않는 데이터입니다.\n");
	else
		printf("%d는 arr[%d]에 존재합니다.\n", key, idx);

	free(arr);
	return 0;
}