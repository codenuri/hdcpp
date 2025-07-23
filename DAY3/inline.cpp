// C++ 에서 inline 함수의 의미
// #1. 함수 호출시 "call" 이 아니라 기계어 코드를 치환해달라
// #2.

inline 
int add(int a, int b)
{
	return a + b;
}

int main()
{
	int ret = add(1,2);
}