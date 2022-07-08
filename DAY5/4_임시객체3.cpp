
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

// 임시객체와 함수 인자
void foo(const Point& pt) {}

int main()
{
//	Point pt(1, 2); // 이 객체를
//	foo(pt);		// 함수 인자로만 사용한다면
					// 함수 호출이 종료되면 더이상 필요 없습니다.
					// 즉시 파괴될까요 ?

	// 어떤 객체를 함수 인자로만 사용한다면.. 
	// 임시객체 형태로 전달하는 것이 효율적입니다.
	// => 실행후, "소멸자 호출이 되는 순서"를 위와 비교해 보세요.
	foo( Point(1, 2) );

	std::cout << "-----" << std::endl;
}





