#include <iostream>

int main()
{
	// #1. primitive type 
	// => std::move 사용해도 아무 효과 없습니다.
	// => 컴파일 에러도 아닙니다.
	int n1 = 10;
	int n2 = std::move(n1);

	// #2. 포인터 타입
	// => std::move 사용해도 아무 효과 없습니다.
	// => 컴파일 에러도 아닙니다.
	int* p1 = new int;
	int* p2 = std::move(p1); // int* p2 = p1 과 동일

	delete p1; 
}




