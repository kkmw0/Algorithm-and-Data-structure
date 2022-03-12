#include <stdio.h>
#include <stdlib.h>
#include "IntQueue.h"
int main(void) {
	IntQueue q;
	if (Initialize(&q, 64) == -1) {
		puts("큐 생성 실패.");
		return 1;
	}

	while (1) {
		int menu, x, key, idx;
		printf("현재 데이터 수 : %d / %d\n", Size(&q), Capacity(&q));
		printf("(1)인큐  (2)디큐  (3)피크  (4)출력  (5)검색  (0)종료 : ");
		scanf_s("%d", &menu);

		if (menu == 0) break;
		switch (menu)
		{
		case 1: /* 인큐 */
			printf("데이터 : ");
			scanf_s("%d", &x);

			if (Enque(&q, x) == -1)
				puts("오류 : 인큐에 실패하였습니다.");
			break;

		case 2: /* 디큐 */
			if (Deque(&q, &x) == -1)
				puts("오류 : 디큐에 실패하였습니다.");
			else
				printf("디큐한 데이터는 %d입니다.\n", x);
			break;

		case 3: /* 피크 */
			if (Peek(&q, &x) == -1)
				puts("오류 : 피크에 실패하였습니다.");
			else
				printf("피크 데이터는 %d입니다.\n", x);
			break;

		case 4: /* 출력 */
			Print(&q);
			break;

		case 5: /* 검색 */
			printf("검색할 데이터 입력 : ");
			scanf_s("%d", &key);

			idx = Search(&q, key);
			if (idx == -1)
				printf("%d는 큐에 존재하지않습니다.\n", key);
			else {
				printf("검색성공!\n");
				printf("%d는 que[%d]에 있습니다.\n", key, idx);
			}
		}
		putchar('\n');
	}
	Terminate(&q);
	return 0;
}