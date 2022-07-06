#include <iostream>

class Point
{
	int x, y;
public:
	// 핵심 : Point는 디폴트 생성자가 없습니다.
//	Point() : x(0), y(0) { std::cout << "Point()" << std::endl; }
	Point(int a, int b) : x(a), y(b) { std::cout << "Point(int, int)" << std::endl; }
};
// Point p1;      // error
// Point p2(0,0); // ok

// 아래 코드가 왜 컴파일에러인지 생각해 보세요
// 에러가 나지 않게 해결해 보세요.

class Rect
{
	Point ptFrom;
	Point ptTo;
public:
	//	  // 컴파일러가 변경한 코드
//	Rect()// Rect() : ptFrom(), ptTo()  <= 여기서 에러. Point는 디폴트생성자 없음

	// 핵심 : 디폴트 생성자가 없는 타입을 멤버 데이타로 사용하면 
	//       반드시 사용자가 아래처럼 명시적으로 생성자를 호출해야 합니다.
	Rect() : ptFrom(0,0), ptTo(0,0)
	{					
		std::cout << "Rect()" << std::endl;
	}
};
int main()
{
	Rect r; 
}




