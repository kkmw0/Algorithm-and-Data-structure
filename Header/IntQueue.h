#ifndef ___IntQueue
#define ___IntQueue

typedef struct {
	int max;
	int num;
	int front;
	int rear;
	int* que;
}IntQueue;

/* 큐 초기화 함수 */
int Initialize(IntQueue* q, int max);

/* 큐에 데이터를 인큐하는 함수 */
int Enque(IntQueue* q, int x);

/* 큐에서 데이터를 디큐하는 함수 */
int Deque(IntQueue* q, int* x);

/* 큐에서 데이터를 피크하는 함수 */
int Peek(const IntQueue* q, int* x);

/* 큐를 비우는 함수 */
void Clear(IntQueue* q);

/* 큐의 최대 용량을 리턴하는 함수 */
int Capacity(const IntQueue* q);

/* 큐에 저장된 데이터 개수를 리턴하는 함수 */
int Size(const IntQueue* q);

/* 큐가 비어있는지 확인하는 함수 */
int isEmpty(const IntQueue* q);

/* 큐가 가득찼는지 확인하는 함수 */
int isFull(const IntQueue* q);

/* 큐에서 검색하는 함수 */
int Search(const IntQueue* q, int x);

/* 큐에 존재하는 데이터를 출력하는 함수 */
void Print(const IntQueue* q);

/* 큐를 종료하는 함수 */
void Terminate(IntQueue* q);

#endif

