// 3_변수1
#include <iostream>

// C++ 은 C언어의 변수 관련 문법을 더욱 발전시켰습니다.
// 교재 18 page ~

struct Point 
{
	int x = 0; // C++11 부터는 구조체 멤버에 초기값 지정 가능합니다
	int y = 0;
};
int main()
{
	int n1 = 0b0101;	// C++11 부터 2진수 표기법 가능합니다.
						// C언어도 "C11" 부터 가능합니다

//	double d = 3'3.11;
	int n2 = 1'000'000; // C++11 의 digit separator 문법
						// 정확한 의미 : 정수형 literal 사이의(실수도가능)
						//				' 는 무시해 달라고 컴파일러에게 요청
	
	struct Point p1;	// C언어는 구조체 변수 만들때 "struct 필요"
	Point p2;			// C++은 struct 필요 없음(C++98부터)
}
