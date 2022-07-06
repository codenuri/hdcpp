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

// godbolt.org 에 위 코드 넣어 보세요

// C++ : 사용자가   "set(int a, int b)" 만들면
//       컴파일러가 "set(Point* this, int a, int b)" 로 변경

// Python : 사용자가 반드시 1번째 인자로 객체 주소를 받도록 만들어라
class Point
	def set(self, a, b):
		self.x = a
		self.y = b

pt = Point()
pt.set(10,20)

// mov에서 값을 넣을때 왜 뒤(마지막인자)에서부터 넣게 되나요?
// => C언어 시절 부터 사용되던 규칙입니다.
// => 32bit.. "마지막 인자" 부터 차례대로 "스택"에
//            그래야지, 가변인자 함수를 쉽게 만들수 있었습니다.
// 
// => 64bit  "마지막 인자" 부터 차례대로 "레지스터"에