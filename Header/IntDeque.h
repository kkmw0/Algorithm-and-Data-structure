#ifndef ___IntDuque
#define ___IntDuque

typedef struct {
	int max;
	int num;
	int front;
	int rear;
	int* deque;
}IntDeque;

/* �� �ʱ�ȭ �Լ� */
int Initialize(IntDeque* d, int max);

/* �� �տ��� �����͸� Ǫ���ϴ� �Լ� */
int Push_front(IntDeque* d, int x);

/* �� �ڿ��� �����͸� Ǫ���ϴ� �Լ� */
int Push_rear(IntDeque* d, int x);

/* �� �տ��� �����͸� ���ϴ� �Լ� */
int Pop_front(IntDeque* d, int* x);

/* �� �ڿ��� �����͸� ���ϴ� �Լ� */
int Pop_rear(IntDeque* d, int* x);

/* �� �տ��� �����͸� ��ũ�ϴ� �Լ� */
int Peek_front(IntDeque* d, int* x);

/* �� �ڿ��� �����͸� ��ũ�ϴ� �Լ� */
int Peek_rear(IntDeque* d, int* x);

/* ���� ���� �Լ� */
void Clear(IntDeque* d);

/* ���� �ִ� �뷮�� �����ϴ� �Լ� */
int Capacity(const IntDeque* d);

/* ���� ����� ������ ������ �����ϴ� �Լ� */
int Size(const IntDeque* d);

/* ���� ����ִ��� Ȯ���ϴ� �Լ� */
int isEmpty(const IntDeque* d);

/* ���� ����á���� Ȯ���ϴ� �Լ� */
int isFull(const IntDeque* d);

/* ������ �˻��ϴ� �Լ� */
int Search(const IntDeque* d, int x);

/* ���� �����ϴ� �����͸� ����ϴ� �Լ� */
void Print(const IntDeque* d);

/* ���� �����ϴ� �Լ� */
void Terminate(IntDeque* d);

#endif