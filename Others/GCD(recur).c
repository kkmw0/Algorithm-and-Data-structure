#include <stdio.h>

int gcd(int x, int y) {
	if (y == 0)
		return x;
	else
		return gcd(y, x % y);
}
int main(void) {
	int a, b, ans;
	printf("�� ���� �Է� : ");
	scanf_s("%d %d", &a, &b);

	printf("�ִ����� : %d\n",gcd(a, b));
	return 0;
}