#include <stdio.h>
#include <stdlib.h>

/* ����� ������ n�� �迭 arr���� key�� ��ġ�ϴ� ��Ҹ� ���� �˻� */
int linear_search(const int arr[], int n, int key) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == key)
			return i;
	}
	return -1;
}
int main(void) {
	int n, key;		/* �迭ũ��, �˻��� ��� */
	int idx;			/* �˻��� ��Ұ� �����ϴ� �迭�� �ε��� */
	int* arr;			/* �����͸� ������ �ִ� �迭 */

	printf("��� ���� : ");
	scanf_s("%d", &n);

	/* �����Ҵ� */
	arr = calloc(n, sizeof(int));
	if (arr == NULL) 
		return -1;

	/* ������ �Է�*/
	for (int i = 0; i < n; i++) {
		printf("arr[%d] : ", i);
		scanf_s("%d", &arr[i]);
	}

	/* �˻� */
	printf("�˻��� ������ : ");
	scanf_s("%d", &key);
	idx = linear_search(arr, n, key);

	if (idx == -1)
		printf("���������ʴ� �������Դϴ�.\n");
	else
		printf("%d�� arr[%d]�� �����մϴ�.\n", key, idx);

	free(arr);
	return 0;
}