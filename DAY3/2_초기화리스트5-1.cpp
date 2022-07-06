#include <iostream>

int g = 10;

class Point
{
public:
	// 필드 초기화를 사용하는 것은 좋습니다. 그런데
	int x = 0;		// 0 같은 literal 값으로 초기화하는 것은 좋습니다.
	int y = ++g;	// 이와같이 하는(++) 코드는 절대 사용하지 마세요. 

	// 위 초기값을 보고		 컴파일러가 변경한 코드
	Point() {}				// Point()      : x(0), y(++g) {}
	Point(int a) : y(a) {}  // Point(int a) : x(0), y(a) {}
};

int main()
{
	Point p1;
	Point p2(1);
	std::cout << g << std::endl; // 결과 예측해 보세요 => 답. 11
								// 앞의 원리를 잘 생각해 보세요
								// 1. 10   2. 11   3. 12
}