#include <stdio.h>
#include <stdlib.h>

/* ����� ������ n�� �迭 arr���� key�� ��ġ�ϴ� ��Ҹ� ���� �˻� */
int binary_search(int arr[], int n, int key) {
	int pl = 0;		/* �˻� ������ �� ���� �ε��� */
	int pr = n - 1;	/* �˻� ������ �� ������ �ε��� */
	int pc;				/* �˻� ������ ��� �ε��� */

	do {
		pc = (pl + pr) / 2;
		if (arr[pc] == key)		/* �˻� ���� */
			return pc;
		else if (arr[pc] > key)
			pr = pc - 1;
		else
			pl = pc + 1;
	} while (pl <= pr);
	return -1;					/* �˻� ���� */
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
	printf("������������ �Է��ϼ���\n");
	printf("arr[0] : ");
	scanf_s("%d", &arr[0]);
	for (int i = 1; i < n; i++) {
		do {
			printf("arr[%d] : ", i);
			scanf_s("%d", &arr[i]);
		} while (arr[i] < arr[i - 1]);
	}

	/* �˻� */
	printf("�˻��� ������ : ");
	scanf_s("%d", &key);
	idx = binary_search(arr, n, key);

	if (idx == -1)
		printf("���������ʴ� �������Դϴ�.\n");
	else
		printf("%d�� arr[%d]�� �����մϴ�.\n", key, idx);

	free(arr);
	return 0;
}