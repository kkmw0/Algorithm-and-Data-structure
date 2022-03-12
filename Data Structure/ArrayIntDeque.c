#include <stdio.h>
#include <stdlib.h>
#include "IntDeque.h"

/* 덱 초기화 */
int Initialize(IntDeque* d, int max) {
	d->num = d->front = d->rear = 0;
	if ((d->deque = calloc(max, sizeof(int))) == NULL) {
		d->max = 0;	/* 존재하지 않는 배열 que에 다른 함수의 접근을 막기위해 0으로 초기화 */
		return -1;
	}
	d->max = max;
	return 0;
}

/* 덱 앞에 데이터를 푸시 */
int Push_front(IntDeque* d, int x) {
	if (isFull(d))
		return -1;
	else {
		d->num++;
		if (--d->front < 0)
			d->front = d->max - 1;
		d->deque[d->front] = x;
		return 0;
	}
}

/* 덱 뒤에 데이터를 푸시 */
int Push_rear(IntDeque* d, int x) {
	if (isFull(d))
		return -1;
	else {
		d->num++;
		d->deque[d->rear++] = x;
		if (d->rear == d->max)
			d->rear = 0;
		return 0;
	}
}

/* 덱 앞에 데이터를 팝 */
int Pop_front(IntDeque* d, int* x) {
	if (isEmpty(d))
		return -1;
	else {
		d->num--;
		*x = d->deque[d->front++];
		if (d->front >= d->max)
			d->front = 0;
		return 0;
	}
}

/* 덱 뒤에 데이터를 팝 */
int Pop_rear(IntDeque* d, int* x) {
	if (isEmpty(d))
		return -1;
	else {
		d->num--;
		if (--d->rear < 0)
			d->rear = d->max - 1;
		*x = d->deque[d->rear];
		return 0;
	}
}

/* 덱 앞에서 데이터를 피크 */
int Peek_front(const IntDeque* d, int* x) {
	if (isEmpty(d))
		return -1;

	*x = d->deque[d->front];
	return 0;
}

/* 덱 뒤에서 데이터를 피크 */
int Peek_rear(const IntDeque* d, int* x) {
	if (isEmpty(d))
		return -1;

	*x = d->deque[d->rear - 1];
	return 0;
}

/* 덱을 비우는 함수 */
void Clear(IntDeque* d) {
	d->num = d->front = d->rear = 0;
}

/* 덱의 최대 용량을 리턴 */
int Capacity(const IntDeque* d) {
	return d->max;
}

/* 덱에 저장된 데이터 개수를 리턴 */
int Size(const IntDeque* d) {
	return d->num;
}

/* 덱이 비어있는지 확인 */
int isEmpty(const IntDeque* d) {
	return d->num <= 0;
}

/* 덱이 가득찼는지 확인 */
int isFull(const IntDeque* d) {
	return d->num >= d->max;
}

/* 덱에서 검색 */
int Search(const IntDeque* d, int x) {
	int idx;
	for (int i = 0; i < d->num; i++) {
		if (d->deque[idx = (i + d->front) % d->max] == x)
			return idx;
	}
	return -1;
}

/* 덱에 존재하는 데이터 출력 */
void Print(const IntDeque* d) {
	int idx;
	for (int i = 0; i < d->num; i++)
		printf("%d ", d->deque[idx = (i + d->front) % d->max]);
	putchar('\n');
}

/* 덱 종료 */
void Terminate(IntDeque* d) {
	if (d->deque != NULL)
		free(d->deque);
	d->max = d->front = d->rear = d->num = 0;
}