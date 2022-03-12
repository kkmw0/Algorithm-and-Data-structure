#include <stdio.h>
#include <stdlib.h>
#include "IntDeque.h"

/* �� �ʱ�ȭ */
int Initialize(IntDeque* d, int max) {
	d->num = d->front = d->rear = 0;
	if ((d->deque = calloc(max, sizeof(int))) == NULL) {
		d->max = 0;	/* �������� �ʴ� �迭 que�� �ٸ� �Լ��� ������ �������� 0���� �ʱ�ȭ */
		return -1;
	}
	d->max = max;
	return 0;
}

/* �� �տ� �����͸� Ǫ�� */
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

/* �� �ڿ� �����͸� Ǫ�� */
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

/* �� �տ� �����͸� �� */
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

/* �� �ڿ� �����͸� �� */
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

/* �� �տ��� �����͸� ��ũ */
int Peek_front(const IntDeque* d, int* x) {
	if (isEmpty(d))
		return -1;

	*x = d->deque[d->front];
	return 0;
}

/* �� �ڿ��� �����͸� ��ũ */
int Peek_rear(const IntDeque* d, int* x) {
	if (isEmpty(d))
		return -1;

	*x = d->deque[d->rear - 1];
	return 0;
}

/* ���� ���� �Լ� */
void Clear(IntDeque* d) {
	d->num = d->front = d->rear = 0;
}

/* ���� �ִ� �뷮�� ���� */
int Capacity(const IntDeque* d) {
	return d->max;
}

/* ���� ����� ������ ������ ���� */
int Size(const IntDeque* d) {
	return d->num;
}

/* ���� ����ִ��� Ȯ�� */
int isEmpty(const IntDeque* d) {
	return d->num <= 0;
}

/* ���� ����á���� Ȯ�� */
int isFull(const IntDeque* d) {
	return d->num >= d->max;
}

/* ������ �˻� */
int Search(const IntDeque* d, int x) {
	int idx;
	for (int i = 0; i < d->num; i++) {
		if (d->deque[idx = (i + d->front) % d->max] == x)
			return idx;
	}
	return -1;
}

/* ���� �����ϴ� ������ ��� */
void Print(const IntDeque* d) {
	int idx;
	for (int i = 0; i < d->num; i++)
		printf("%d ", d->deque[idx = (i + d->front) % d->max]);
	putchar('\n');
}

/* �� ���� */
void Terminate(IntDeque* d) {
	if (d->deque != NULL)
		free(d->deque);
	d->max = d->front = d->rear = d->num = 0;
}