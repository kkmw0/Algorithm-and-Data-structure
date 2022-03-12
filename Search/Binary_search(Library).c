#include <stdio.h>
#include <stdlib.h>

/* ����� ������ n�� �迭 arr���� key�� ��ġ�ϴ� ��Ҹ� ���� �˻�(���̺귯�� ���) */
/* ������ ���ϴ� �Լ�(��������) */
int int_cmp(const int *a, const int *b) {
	if (*a > *b)
		return 1;
	else if (*a < *b)
		return -1;
	else
		return 0;
}
int main(void) {
	int n, key;		/* �迭ũ��, �˻��� ��� */
	int* arr;			/* �����͸� ������ �ִ� �迭 */
	int* p;				/* �˻��� ��ҿ� ���� ������ */

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
	p = bsearch(&key, arr, n, sizeof(int), (int(*)(const void*, const void*))int_cmp);

	if (p == NULL)
		printf("���������ʴ� �������Դϴ�.\n");
	else
		printf("%d�� arr[%d]�� �����մϴ�.\n", key, (int)(p - arr));

	free(arr);
	return 0;
}