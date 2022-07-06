#include <iostream>

// 방법 2. 전역변수 사용
// => 전역변수는 모든 객체가 공유할수 있다.
// => 객체의 갯수 파악 성공

// 그런데.!!!
// => 전역변수는 어디서도 접근 가능하기 때문에 항상 위험하다!!
// => 접근지정자(private)로 보호할수 없을까 ??

int cnt = 0;

class Car
{
	int color;
public:
	Car() { ++cnt; }
	~Car() { --cnt; }
};

int main()
{
	Car c1;
	Car c2;


//	count = 20; // 이렇게 하려고 했는데..
	cnt = 20;   // 오타가 있었다.. 이런이름의 전역변수가 있으므로 컴파일 ok.		

	std::cout << cnt << std::endl; // 2. 
}

