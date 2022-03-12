#include <stdio.h>
#include <stdlib.h>

/* 요소의 개수가 n인 배열 arr에서 key와 일치하는 요소를 선형 검색(보초법) */
int linear_search(int arr[], int n, int key) {
	int idx = 0;
	arr[n] = key;		/* 보초 추가 */

	while (1) {
		if (arr[idx] == key)
			break;
		idx++;
	}
	/* 검색한 결과가 보초면 -1을, 아니면 배열의 인덱스를 리턴 */
	return idx == n ? -1 : idx;
}
int main(void) {
	int n, key;		/* 배열크기, 검색할 요소 */
	int idx;			/* 검색한 요소가 존재하는 배열의 인덱스 */
	int* arr;			/* 데이터를 가지고 있는 배열 */

	printf("요소 개수 : ");
	scanf_s("%d", &n);

	/* 동적할당(보초를 추가하기 위해 요소의 개수가 n + 1인 배열 생성) */
	arr = calloc(n + 1, sizeof(int));
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