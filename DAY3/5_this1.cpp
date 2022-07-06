// 5_this1.cpp      126 page ~
#include <iostream>

class Point
{
	int x, y;
public:
	// 사용자 코드			// 컴파일러가 변경한 코드
	void set(int a, int b)	// void set(Point* this, int a, int b)
	{						// {
		x = a;				//		this->x = a;
		y = b;				//		this->y = b; // 이렇게 변경됩니다.
			
		// 멤버 함수안에서 사용하는 "this"
		// => 현재 멤버함수를 호출할때 사용한 객체의 주소
		std::cout << this << std::endl;
	}
};


int main()
{
	Point p1;
	Point p2;
	std::cout << "p1 : " << &p1 << std::endl;
	std::cout << "p2 : " << &p2 << std::endl;

	p1.set(10, 20); // set(&p1, 10, 20)
					// 처럼 컴파일러가 코드를 
					// 변경합니다.
}
