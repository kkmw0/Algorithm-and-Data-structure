#ifndef ___IntStack
#define ___IntStack

typedef struct {
	int max;		/* ���� �뷮*/
	int ptr;		/* ���� ������ */
	int* stk;		/* ������ ù ��ҿ� ���� ������ */
}IntStack;

/* ���� �ʱ�ȭ �Լ� */
int Initialize(IntStack* s, int max);

/* ���ÿ� �����͸� Ǫ���ϴ� �Լ� */
int Push(IntStack* s, int x);

/* ���ÿ��� �����͸� ���ϴ� �Լ� */
int Pop(IntStack* s, int *x);

/* ���ÿ��� �����͸� ��ũ�ϴ� �Լ� */
int Peek(const IntStack* s, int *x);

/* ������ ���� �Լ� */
void Clear(IntStack* s);

/* ������ �ִ� �뷮�� �����ϴ� �Լ� */
int Capacity(const IntStack* s);

/* ������ ������ ������ �����ϴ� �Լ� */
int Size(const IntStack* s);

/* ������ ����ִ��� Ȯ���ϴ� �Լ� */
int isEmpty(const IntStack* s);

/* ������ ����á���� Ȯ���ϴ� �Լ� */
int isFull(const IntStack* s);

/* ���ÿ��� �˻��ϴ� �Լ� */
int Search(const IntStack* s, int x);

/* ���ÿ� �����ϴ� �����͸� ����ϴ� �Լ� */
void Print(const IntStack* s);

/* ������ �����ϴ� �Լ� */
void Terminate(IntStack* s);

#endif

