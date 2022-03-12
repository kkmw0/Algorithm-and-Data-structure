#ifndef ___IntDuque
#define ___IntDuque

typedef struct {
	int max;
	int num;
	int front;
	int rear;
	int* deque;
}IntDeque;

/* 덱 초기화 함수 */
int Initialize(IntDeque* d, int max);

/* 덱 앞에서 데이터를 푸시하는 함수 */
int Push_front(IntDeque* d, int x);

/* 덱 뒤에서 데이터를 푸시하는 함수 */
int Push_rear(IntDeque* d, int x);

/* 덱 앞에서 데이터를 팝하는 함수 */
int Pop_front(IntDeque* d, int* x);

/* 덱 뒤에서 데이터를 팝하는 함수 */
int Pop_rear(IntDeque* d, int* x);

/* 덱 앞에서 데이터를 피크하는 함수 */
int Peek_front(IntDeque* d, int* x);

/* 덱 뒤에서 데이터를 피크하는 함수 */
int Peek_rear(IntDeque* d, int* x);

/* 덱을 비우는 함수 */
void Clear(IntDeque* d);

/* 덱의 최대 용량을 리턴하는 함수 */
int Capacity(const IntDeque* d);

/* 덱에 저장된 데이터 개수를 리턴하는 함수 */
int Size(const IntDeque* d);

/* 덱이 비어있는지 확인하는 함수 */
int isEmpty(const IntDeque* d);

/* 덱이 가득찼는지 확인하는 함수 */
int isFull(const IntDeque* d);

/* 덱에서 검색하는 함수 */
int Search(const IntDeque* d, int x);

/* 덱에 존재하는 데이터를 출력하는 함수 */
void Print(const IntDeque* d);

/* 덱을 종료하는 함수 */
void Terminate(IntDeque* d);

#endif