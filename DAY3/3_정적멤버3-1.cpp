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
	Car c1;
	Car c2;

	// static member에 접근하는 2가지 방법
	// 1. 클래스 이름으로 접근 : Car::cnt
	// 2. 객체 이름으로 접근   : c1.cnt
	std::cout << Car::cnt << std::endl; 
	std::cout << c1.cnt   << std::endl;
	std::cout << c2.cnt   << std::endl;
}
