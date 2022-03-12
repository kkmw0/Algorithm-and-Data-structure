#ifndef ___IntQueue
#define ___IntQueue

typedef struct {
	int max;
	int num;
	int front;
	int rear;
	int* que;
}IntQueue;

/* ť �ʱ�ȭ �Լ� */
int Initialize(IntQueue* q, int max);

/* ť�� �����͸� ��ť�ϴ� �Լ� */
int Enque(IntQueue* q, int x);

/* ť���� �����͸� ��ť�ϴ� �Լ� */
int Deque(IntQueue* q, int* x);

/* ť���� �����͸� ��ũ�ϴ� �Լ� */
int Peek(const IntQueue* q, int* x);

/* ť�� ���� �Լ� */
void Clear(IntQueue* q);

/* ť�� �ִ� �뷮�� �����ϴ� �Լ� */
int Capacity(const IntQueue* q);

/* ť�� ����� ������ ������ �����ϴ� �Լ� */
int Size(const IntQueue* q);

/* ť�� ����ִ��� Ȯ���ϴ� �Լ� */
int isEmpty(const IntQueue* q);

/* ť�� ����á���� Ȯ���ϴ� �Լ� */
int isFull(const IntQueue* q);

/* ť���� �˻��ϴ� �Լ� */
int Search(const IntQueue* q, int x);

/* ť�� �����ϴ� �����͸� ����ϴ� �Լ� */
void Print(const IntQueue* q);

/* ť�� �����ϴ� �Լ� */
void Terminate(IntQueue* q);

#endif

