// 정적멤버5,  4번 복사해오세요.
#include <iostream>

class Car
{
	int color;
	static int cnt;
public:
	Car() { ++cnt; }
	~Car() { --cnt; }

	static int getCount() { return cnt; }
};

int Car::cnt = 0; 


int main()
{
	std::cout << Car::getCount() << std::endl;
}

