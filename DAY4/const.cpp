//const.cpp 
class Point
{
public:
	int x = 0;
	int y = 0;

	void set(int a, int b) { x = a; y = b;}

	// 상수 멤버 함수 : 멤버 함수 뒤에 const 붙은것
	// 특징 #1. 멤버 함수안에서 멤버 데이타 수정 안됨
	// 특징 #2. 상수 객체는 상수 멤버 함수만 호출 가능
	void print() const 
	{
		x = 10; // error
		std::cout << x << std::endl;
	}
};
int main()
{
	const Point p;

	p.x = 10;		// error. public 이지만 p는 상수객체
	p.set(1, 2);	// error
	p.print();		// error
					// 상수 멤버 함수라면 ok

	// 핵심 : 상수객체는 상수 멤버함수만 호출가능하다.
}