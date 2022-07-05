#include <iostream>

// 객체지향 프로그래밍 핵심 1. 프로그램에서 필요한 타입을 먼저 설계하자.
// 2. 타입을 만들때 "상태를 나타내는 데이타" 와 상태를 가지고 "연산을 수행하는 함수"
//    를 묶어서 만들자

// C언어   구조체 : 함수를 포함할수 없다.
// C++언어 구조체 : 함수를 포함할수 있다.

// 함수를 포함해서 얻는 장점은 뭡니까 ?
// => 데이타를 함수 인자로 별도로 보낼 필요가 없다.(함수가 간결)
// => 객체지향 언어의 다양한 특징을 활용할수 있다.

struct Rect
{
	// 아래 같은 데이타를 "멤버 데이타(필드)"라고 합니다.
	int left;
	int top;
	int right;
	int bottom;

	// 아래 함수를 "멤버함수(메소드)" 라고 합니다.
	// 멤버 함수는 멤버데이타에 바로 접근할수 있습니다.
	int getArea()
	{
		return (right - left) * (bottom - top);
	}
	void draw()
	{
		std::cout << "draw rect" << std::endl;
	}
};
int main()
{
	Rect r = { 1,1,10,10 };

//	int n1 = getRectArea(r); // C 언어는 이 코드가 최선 입니다.
//	drawRect(r);

	int n1 = r.getArea(); // C++은 구조체 안에 함수를 넣을수 있기 때문에 
	r.draw();			  // 이렇게 가능합니다.
}

