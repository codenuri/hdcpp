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
	std::cout << Car::cnt << std::endl;

	Car c1;
	Car c2;

	std::cout << Car::cnt << std::endl;
	std::cout << c1.cnt << std::endl;
	std::cout << c2.cnt << std::endl;
}
