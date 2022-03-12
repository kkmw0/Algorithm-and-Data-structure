#include <stdio.h>
#include <stdlib.h>
#include "IntQueue.h"

/* 큐 초기화 */
int Initialize(IntQueue* q, int max) {
	q->num = q->front = q->rear = 0;
	if ((q->que = calloc(max, sizeof(int))) == NULL) {
		q->max = 0;	/* 존재하지 않는 배열 que에 다른 함수의 접근을 막기위해 0으로 초기화 */
		return -1;
	}
	q->max = max;
	return 0;
}

/* 큐에 데이터를 인큐 */
int Enque(IntQueue* q, int x) {
	if (q->num >= q->max)
		return -1;
	else {
		q->num++;
		q->que[q->rear++] = x;

		if (q->rear >= q->max)
			q->rear = 0;
		return 0;
	}
}

/* 큐에서 데이터를 디큐 */
int Deque(IntQueue* q, int* x) {
	if (q->num <= 0)
		return -1;
	else {
		q->num--;
		*x = q->que[q->front++];

		if (q->front >= q->max)
			q->front = 0;
		return 0;
	}
}

/* 큐에서 데이터를 피크 */
int Peek(const IntQueue* q, int* x) {
	if (q->num <= 0)
		return -1;

	*x = q->que[q->front];
	return 0;
}

/* 큐를 비우는 함수 */
void Clear(IntQueue* q) {
	q->num = q->front = q->rear = 0;
}

/* 큐의 최대 용량을 리턴 */
int Capacity(const IntQueue* q) {
	return q->max;
}

/* 큐에 저장된 데이터 개수를 리턴 */
int Size(const IntQueue* q) {
	return q->num;
}

/* 큐가 비어있는지 확인 */
int isEmpty(const IntQueue* q) {
	return q->num <= 0;
}

/* 큐가 가득찼는지 확인 */
int isFull(const IntQueue* q) {
	return q->num >= q->max;
}

/* 큐에서 검색 */
int Search(const IntQueue* q, int x) {
	int idx;
	for (int i = 0; i < q->num; i++) {
		if (q->que[idx = (i + q->front) % q->max] == x)
			return idx;
	}
	return -1;
}

/* 큐에 존재하는 데이터 출력 */
void Print(const IntQueue* q) {
	int idx;
	for (int i = 0; i < q->num; i++)
		printf("%d ", q->que[idx = (i + q->front) % q->max]);
	putchar('\n');
}

/* 큐 종료 */
void Terminate(IntQueue* q) {
	if (q->que != NULL)
		free(q->que);
	q->max = q->front = q->rear = q->num = 0;
}