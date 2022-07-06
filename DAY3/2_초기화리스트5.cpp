#include <iostream>

// member field initialization
class Point
{
	// C++11 부터는 멤버데이타 선언시 바로 초기값을 넣을수 있습니다
	int x = 0;  // 이렇게 해도 되고
	int y{ 0 }; // 이렇게 해도 됩니다.
public:
	Point() {}
	Point(int a)        : x(a) {}
	Point(int a, int b) : x(a), y(b) {}
};

// 위 코드는 결국 컴파일러에 의해서 아래 처럼 변경됩니다.
class Point
{
	int x; // = 0;
	int y; // { 0 };
public:
	// 위 필드 초기화를 보고 아래처럼 생성자를 변경
	Point()      : x(0), y(0) {}
	Point(int a) : x(a), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

int main()
{

}




