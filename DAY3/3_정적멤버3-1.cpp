#include <iostream>


class Car
{
	int color;
public:
	static int cnt; 

	Car() { ++cnt; }
	~Car() { --cnt; }
};
int Car::cnt = 0;

int main()
{
	// 객체가 없어도 static 멤버 데이타는 메모리에 있으므로
	// 객체 없는 상태에서 아래 처럼 접근 가능합니다.
	std::cout << Car::cnt << std::endl;

	Car c1;
	Car c2;

	// static member에 접근하는 2가지 방법
	// 1. 클래스 이름으로 접근 : Car::cnt
	//		=> 해당 멤버가 static 이라는것을 명확히 알수 있다. 권장
	
	// 2. 객체 이름으로 접근   : c1.cnt
	//		=> 해당 멤버가 static 이라는 것을 알수 없다. 

	// java, C# 등의 대부분의 다른 언어는 "클래스이름" 으로만 접근 가능합니다.
	// 그리고, :: 이 아니라 . 사용
	// java, C# : "Car.cnt"

	std::cout << Car::cnt << std::endl; 
	std::cout << c1.cnt   << std::endl;
	std::cout << c2.cnt   << std::endl;
}
