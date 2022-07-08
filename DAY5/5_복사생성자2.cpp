// 2_복사생성자2.cpp
#include <iostream>

class Point
{
	int x, y;
public:
	Point() : x(0), y(0) {}  
	Point(int a, int b) : x(a), y(b) {}  

	// 복사 생성자 
	Point(const Point& p) : x(p.x), y(p.y)
	{
		std::cout << "copy ctor" << std::endl;
	}
};

void f1(Point  p) {} 
void f2(Point& p) {} 

Point pt(1, 1);

Point  f3() { return pt; }	// 이순간 리턴용 임시객체를 생성
							// => pt를 복사 해서 만들기 때문에 "복사생성자" 호출
Point& f4() { return pt; } 

int main()
{
	Point p1(1, 2);		

	// 복사 생성자가 사용되는 경우 3가지
	// 1. 자신과 동일한 타입의 객체로 초기화 될때
//	Point p2(p1); 
//	Point p3 = p1;
//	Point p4{ p1 };
//	Point p5 = { p1 };


	// 2. 함수가 객체를 call by value 로 받을때
	f1(p1); // Point  p = p1 의 형태로 전달.. 복사 생성자 호출
	f2(p1); // Point& p = p1 의 형태로 전달. 객체 생성이 아니므로 복사 생성자
			//							호출 안됨.

	// 3. 함수가 객체를 값으로 반환 할때
	f3(); // 리턴용 임시객체를 만들때 복사 생성자 사용
	f4();
}



