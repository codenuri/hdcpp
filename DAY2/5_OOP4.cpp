#include <iostream>

struct Rect
{
	int left;
	int top;
	int right;
	int bottom;

	int getArea() { return (right - left) * (bottom - top); }
	void draw() { std::cout << "draw rect" << std::endl; }
};
int main()
{
	// 구조체에 함수가 있어도 변수 생성시
	// 실제 스택메모리에는 멤버 데이타만 놓이게 됩니다.

	// Rect의 메모리 Layout
	// 1. 멤버 함수는 Rect의 변수를 생성하지 않아도 항상 코드메모리에 
	//    한개만 있습니다.

	// 2. Rect 타입의 변수 생성시
	//    => "멤버 변수" 만 데이타 메모리(스택) 에 생성됩니다.
	Rect r1 = { 1,1,10,10 }; 
	Rect r2 = { 1,1,10,10 };

	std::cout << sizeof(r1) << std::endl; // 16(int 4개)


	// 용어 정리
	int n = 10; // n : "변" 하는 "수" => 변수(variable)

	Rect rc = { 1,1,10,10 }; // "변수" 보다는 "객체(object)"라고 합니다.

	// 객체(object) : 세상에 존재하는 모든 사물 이라는 의미..
	//              엄격히 말하면 n 도 객체 입니다.

	// 그런데, 관례적으로..
	// primitive 타입을   메모리에 생성한것 : 변수
	// user define 타입을 메모리에 생성한것 : 객체
}
