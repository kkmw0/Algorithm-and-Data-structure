#ifndef ___IntStack
#define ___IntStack

typedef struct {
	int max;		/* 스택 용량*/
	int ptr;		/* 스택 포인터 */
	int* stk;		/* 스택의 첫 요소에 대한 포인터 */
}IntStack;

/* 스택 초기화 함수 */
int Initialize(IntStack* s, int max);

/* 스택에 데이터를 푸시하는 함수 */
int Push(IntStack* s, int x);

/* 스택에서 데이터를 팝하는 함수 */
int Pop(IntStack* s, int *x);

/* 스택에서 데이터를 피크하는 함수 */
int Peek(const IntStack* s, int *x);

/* 스택을 비우는 함수 */
void Clear(IntStack* s);

/* 스택의 최대 용량을 리턴하는 함수 */
int Capacity(const IntStack* s);

/* 스택의 데이터 개수를 리턴하는 함수 */
int Size(const IntStack* s);

/* 스택이 비어있는지 확인하는 함수 */
int isEmpty(const IntStack* s);

/* 스택이 가득찼는지 확인하는 함수 */
int isFull(const IntStack* s);

/* 스택에서 검색하는 함수 */
int Search(const IntStack* s, int x);

/* 스택에 존재하는 데이터를 출력하는 함수 */
void Print(const IntStack* s);

/* 스택을 종료하는 함수 */
void Terminate(IntStack* s);

#endif

