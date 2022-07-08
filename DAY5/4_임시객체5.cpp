#include <iostream>

class Counter
{
	int cnt = 0;
public:
	// 아래 2줄의 차이점을 정확히 알아야 합니다.
//	Counter  increment()	// *this 의 복사본(임시객체) 반환
	Counter& increment()	// 임시객체를 만들지 말라는 의도..
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

