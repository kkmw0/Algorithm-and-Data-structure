#include <stdio.h>

int pos[8];			/* �� ������ ���� ��ġ�� ��Ÿ���� �迭  */
int flag_a[8];			/* �� �࿡ ���� ��ġ�ߴ��� üũ�ϴ� �迭 */
int flag_b[15];		/* �밢�� /�� ���� ��ġ�ߴ��� üũ�ϴ� �迭 */
int flag_c[15];		/* �밢��  ���� ���� ��ġ�ߴ��� üũ�ϴ� �迭 */

/* �� ���� ���� ��ġ�� ��� */
void Print(void) {
	for (int i = 0; i < 8; i++)
		printf("%d ", pos[i]);
	putchar('\n');
}

/* i���� ���� ��ġ */
void set(int i) {
	for (int j = 0; j < 8; j++) {
		if (!flag_a[j] && !flag_b[i + j] && !flag_c[7 - j + i]) {
			pos[i] = j;
			if (i == 7)
				Print();
			else {
				flag_a[j] = flag_b[i + j] = flag_c[7 - j + i] = 1;
				set(i + 1);
				flag_a[j] = flag_b[i + j] = flag_c[7 - j + i] = 0;
			}
		}
	}
}

int main(void) {
	for (int i = 0; i < 8; i++)
		flag_a[i] = 0;
	for (int j = 0; j < 15; j++)
		flag_b[j] = flag_c[j] = 0;

	set(0);

	return 0;
}