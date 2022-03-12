#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

/* 스택 초기화 */
int Initialize(IntStack* s, int max) {
	s->ptr = 0;
	if ((s->stk = calloc(max, sizeof(int))) == NULL) {
		s->max = 0;		/* 존재하지 않는 배열 stk에 다른 함수의 접근을 막기위해 0으로 초기화 */
		return -1;
	}
	s->max = max;
	return 0;
}

/* 스택에 데이터 푸시 */
int Push(IntStack* s, int x) {
	if (s->ptr >= s->max)		/* 스택이 가득 찬 경우 */
		return -1;
	s->stk[s->ptr++] = x;
	return 0;
}

/* 스택에서 데이터를 팝 */
int Pop(IntStack* s, int* x) {
	if (s->ptr <= 0)					/* 스택이 비어 있는 경우 */
		return -1;
	*x = s->stk[--s->ptr];
	return 0;
}

/* 스택에서 데이터를 피크 */
int Peek(const IntStack* s, int* x) {
	if (s->ptr <= 0)					/* 스택이 비어 있는 경우 */
		return -1;
	*x = s->stk[s->ptr - 1];
	return 0;
}

/* 스택 비우기 */
void Clear(IntStack* s) {
	s->ptr = 0;
}

/* 스택의 최대 용량을 리턴 */
int Capacity(const IntStack* s) {
	return s->max;
}

/* 스택의 데이터 개수를 리턴 */
int Size(const IntStack* s) {
	return s->ptr;
}

/* 스택이 비어있는지 확인 */
int isEmpty(const IntStack* s) {
	return s->ptr <= 0;
}

/* 스택이 가득찼는지 확인 */
int isFull(const IntStack* s) {
	return s->ptr >= s->max;
}

/* 스택에서 검색 */
int Search(const IntStack* s, int x) {
	for (int i = s->ptr - 1; i >= 0; i--) {
		if (s->stk[i] == x)
			return i;
	}
	return -1;
}

/* 스택에 존재하는 데이터 출력 */
void Print(const IntStack* s) {
	for (int i = 0; i < s->ptr; i++) {
		printf("%d ", s->stk[i]);
	}
	putchar('\n');
}

/* 스택 종료 */
void Terminate(IntStack* s) {
	if (s->stk != NULL)
		free(s->stk);
	s->max = s->ptr = 0;
}