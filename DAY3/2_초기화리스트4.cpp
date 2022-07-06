#include <iostream>

// 선언과 구현의 분리
class Point
{
	int x, y;
public:
	Point(int a = 0, int b = 0);
};

// 핵심 1. 초기화 리스트는 생성자 구현부(.cpp)에 있어야 합니다.
//     2. 디폴트 인자는 선언부에만 표기하세요

Point::Point(int a /*= 0*/, int b /*= 0*/) 
	: x(a), 
	  y(b) 
{
}



int main()
{

}




