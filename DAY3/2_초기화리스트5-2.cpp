// 2_초기화리스트5-2 
#include <iostream>

class Point
{
	int x, y;
public:
	// 핵심 : 디폴트 생성자가 없습니다
//	Point() : x(0), y(0) { std::cout << "Point()" << std::endl; }
	Point(int a, int b) : x(a), y(b) { std::cout << "Point(int, int)" << std::endl; }
};

// 디폴트 생성자가 없는 타입이 멤버 데이타로 있을때 해결책 2가지
class Rect
{
	// 방법 1. 필드 초기화 사용 - C++11 부터 가능
	Point ptFrom{0, 0};
	Point ptTo{0, 0};

//	Point ptTo( 0, 0 ); // 주의, 여기서는 () 는 안됩니다. {}만 가능

public:
	// 방법 2. 초기화 리스트에서 명시적으로 멤버 생성자 호출 
	// => C++98 시절의 유일한 방법
	Rect() : ptFrom(0,0), ptTo(0,0)
	{		
		std::cout << "Rect()" << std::endl;
	}
	// 인자를 받아서 멤버 데이타를 초기화 하려면 "방법2"를 사용
	Rect(int x1, int y1, int x2, int y2) : ptFrom(x1, y1), ptTo(x2, y2)
	{
	}
};


int main()
{
	Rect r; 
}




