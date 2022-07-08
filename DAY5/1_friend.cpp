#include <iostream>

class Bike
{
	int gear = 0;
public:
	void setGear(int n) { gear = n; }

	// 프렌드 함수 : 멤버 함수는 아니지만, private 에 접근할수 있게 해달라는 의미.
	// 1. 멤버함수로 하면 되는데, 왜 멤버로 하지 않고 일반함수로 하나요 ?
	// => 멤버함수로 할수 없을때가 있습니다.

	// 2. getter/setter 를 만들면 되지 않나요 ?
	// => getter/setter 를 만드는 것은 모든 곳에서 접근을 허용하겠다는 의미
	// => 아래의 경우는 fixBike 만 접근을 허용하겠다는 것

	friend void fixBike(Bike& b);
	
};


// 아래 함수는 Bike 멤버 함수가 아닙니다.
void fixBike(Bike& b)
{
	b.gear = 10; // private 멤버 접근

	Bike b2;
	b2.gear = 20;
}



int main()
{
	Bike b;
	fixBike(b);
}

