#include <stdio.h>
#include <stdlib.h>

/* 정수 n보다 작거나 같은 소수 출력 */
int main(void) {
	int n, cnt = 0;			/* 소수를 저장하는 배열의 인덱스 cnt선언 */
	int* prime;				/* 소수를 저장하는 배열 */

	printf("정수입력 : ");
	scanf_s("%d", &n);

	prime = calloc(n, sizeof(int));		/* 동적할당 */
	if (prime == NULL) {
		printf("동적할당 실패!\n");
		return -1;
	}
	/* 소수 저장 */
	prime[cnt++] = 2;	
	prime[cnt++] = 3;	

	/* 짝수는 모두 2의 배수이므로 홀수만을 대상으로 함 */
	for (int i = 5; i <= n; i += 2) {
		int flag = 0;
		for (int j = 1; prime[j] * prime[j] <= i; j++) {
			/* 나누어 떨어지면 소수가 아니므로 반복문 탈출 */
			if (i % prime[j] == 0) {
				flag = 1;
				break;
			}
		}
		/* 나누어 떨어지지 않았으면 소수이므로 배열에 저장 */
		if (!flag) {
			prime[cnt++] = i;
		}
	}
	/* 소수 출력 */
	for (int i = 0; prime[i] != 0; i++) {
		printf("%d\n", prime[i]);
	}

	free(prime);
	return 0;
}