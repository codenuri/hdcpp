// C스타일 캐스팅은 너무 위험 합니다.
/*
int main()
{
	int n1 = 0;

	// 아래 코드만 보면, 이캐스팅이 "개발자 의도"인지" "실수"인지
	// 구별되지 않습니다.
	double* p1 = (double*)&n1;

	*p1 = 3.4;  // 이 경우를 생각해 보세요
}
*/
#include <iostream>

int main()
{
	const int c = 10; // 상수

//	int* p = &c; // error
	int* p = (int*)&c; // ok.. C 스타일 캐스팅은 거의 성공(막강한 힘)

	*p = 20;

	std::cout << c  << std::endl; // 10 ( 단, 컴파일러마다 다를수 있음)
	std::cout << *p << std::endl; // 20
}

