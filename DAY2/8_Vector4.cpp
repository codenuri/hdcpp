#include <iostream>

// 객체지향 : 필요한 타입을 먼저 설계 하자.!!

// Person, Rect 등만 타입이 아닙니다.

// 추상화된 많은 개념도 타입화 하면 편리합니다.

// 동적 배열(vector)를 타입화 해 봅시다.
class vector
{

public:

};

int main()
{
	vector v(5); // 크기가 5인 동적 배열

	v.resize(10); // 크기를 10으로!
}