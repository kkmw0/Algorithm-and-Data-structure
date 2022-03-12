#include <stdio.h>
#include <stdlib.h>

/* ���� n���� �۰ų� ���� �Ҽ� ��� */
int main(void) {
	int n, cnt = 0;			/* �Ҽ��� �����ϴ� �迭�� �ε��� cnt���� */
	int* prime;				/* �Ҽ��� �����ϴ� �迭 */

	printf("�����Է� : ");
	scanf_s("%d", &n);

	prime = calloc(n, sizeof(int));		/* �����Ҵ� */
	if (prime == NULL) {
		printf("�����Ҵ� ����!\n");
		return -1;
	}
	/* �Ҽ� ���� */
	prime[cnt++] = 2;	
	prime[cnt++] = 3;	

	/* ¦���� ��� 2�� ����̹Ƿ� Ȧ������ ������� �� */
	for (int i = 5; i <= n; i += 2) {
		int flag = 0;
		for (int j = 1; prime[j] * prime[j] <= i; j++) {
			/* ������ �������� �Ҽ��� �ƴϹǷ� �ݺ��� Ż�� */
			if (i % prime[j] == 0) {
				flag = 1;
				break;
			}
		}
		/* ������ �������� �ʾ����� �Ҽ��̹Ƿ� �迭�� ���� */
		if (!flag) {
			prime[cnt++] = i;
		}
	}
	/* �Ҽ� ��� */
	for (int i = 0; prime[i] != 0; i++) {
		printf("%d\n", prime[i]);
	}

	free(prime);
	return 0;
}