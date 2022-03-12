#include <stdio.h>

int pos[8];			/* 각 열에서 퀸의 위치를 나타내는 배열  */
int flag_a[8];			/* 각 행에 퀸을 배치했는지 체크하는 배열 */
int flag_b[15];		/* 대각선 /에 퀸을 배치했는지 체크하는 배열 */
int flag_c[15];		/* 대각선  ＼에 퀸을 배치했는지 체크하는 배열 */

/* 각 열의 퀸의 위치를 출력 */
void Print(void) {
	for (int i = 0; i < 8; i++)
		printf("%d ", pos[i]);
	putchar('\n');
}

/* i열에 퀸을 배치 */
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