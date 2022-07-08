#include <iostream>

class Counter
{
	int cnt = 0;
public:
	Counter increment()
	{
		++cnt;
		return *this;
	}
	int get() const { return cnt; }

	~Counter() { std::cout << "~Counter" << std::endl; }
};

int main()
{
	Counter c;
//	c.increment();
//	c.increment();
//	c.increment();

	// *this 를 반환하면 "멤버함수를 연속적으로" 호출 가능합니다.
	c.increment().increment().increment();

	std::cout << c.get() << std::endl; // 1
}

