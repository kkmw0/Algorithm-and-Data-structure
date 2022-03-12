#include <stdio.h>
#include <stdlib.h>

/* ����� ������ n�� �迭 arr���� key�� ��ġ�ϴ� ��Ҹ� ���� �˻�(���ʹ�) */
int linear_search(int arr[], int n, int key) {
	int idx = 0;
	arr[n] = key;		/* ���� �߰� */

	while (1) {
		if (arr[idx] == key)
			break;
		idx++;
	}
	/* �˻��� ����� ���ʸ� -1��, �ƴϸ� �迭�� �ε����� ���� */
	return idx == n ? -1 : idx;
}
int main(void) {
	int n, key;		/* �迭ũ��, �˻��� ��� */
	int idx;			/* �˻��� ��Ұ� �����ϴ� �迭�� �ε��� */
	int* arr;			/* �����͸� ������ �ִ� �迭 */

	printf("��� ���� : ");
	scanf_s("%d", &n);

	/* �����Ҵ�(���ʸ� �߰��ϱ� ���� ����� ������ n + 1�� �迭 ����) */
	arr = calloc(n + 1, sizeof(int));
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