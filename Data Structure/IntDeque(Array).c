#include <stdio.h>
#include <stdlib.h>
#include "IntDeque.h"
int main(void) {
	IntDeque d;
	if (Initialize(&d, 64) == -1) {
		puts("큐 생성 실패.");
		return 1;
	}

	while (1) {
		int menu, x, key, idx;
		printf("현재 데이터 수 : %d / %d\n", Size(&d), Capacity(&d));
		printf("(1)Push_front  (2)Push_rear  (3)Pop_front  (4)Pop_rear  (5)Peek_front  (6)Peek_rear\n");
		printf("(7)Search      (8)Print      (9)Reset      (0)Exit : ");
		scanf_s("%d", &menu);

		if (menu == 0) break;
		switch (menu)
		{
		case 1: /* Push_front */
			printf("데이터 : ");
			scanf_s("%d", &x);

			if (Push_front(&d, x) == -1)
				puts("오류 : Push_front에 실패하였습니다.");
			break;

		case 2: /* Push_rear */
			printf("데이터 : ");
			scanf_s("%d", &x);

			if (Push_rear(&d, x) == -1)
				puts("오류 : Push_rear에 실패하였습니다.");
			break;

		case 3: /* Pop_front */
			if (Pop_front(&d, &x) == -1)
				puts("오류 : Pop_front에 실패하였습니다.");
			else
				printf("팝 데이터는 %d입니다.\n", x);
			break;

		case 4: /* Pop_rear */
			if (Pop_rear(&d, &x) == -1)
				puts("오류 : Pop_rear에 실패하였습니다.");
			else
				printf("팝 데이터는 %d입니다.\n", x);
			break;

		case 5: /* Peek_front */
			if (Peek_front(&d, &x) == -1)
				puts("오류 : Peek_front에 실패하였습니다.");
			else
				printf("피크 데이터는 %d입니다.\n", x);
			break;

		case 6: /* Peek_rear */
			if (Peek_rear(&d, &x) == -1)
				puts("오류 : Peek_rear에 실패하였습니다.");
			else
				printf("피크 데이터는 %d입니다.\n", x);
			break;

		case 7: /* Search */
			printf("검색할 데이터 입력 : ");
			scanf_s("%d", &key);

			idx = Search(&d, key);
			if (idx == -1)
				printf("%d는 덱에 존재하지않습니다.\n", key);
			else {
				printf("검색성공!\n");
				printf("%d는 deque[%d]에 있습니다.\n", key, idx);
			}
			break;

		case 8: /* Print */
			Print(&d);
			break;

		case 9: /* Clear */
			Clear(&d);
		}
		putchar('\n');
	}
	Terminate(&d);
	return 0;
}