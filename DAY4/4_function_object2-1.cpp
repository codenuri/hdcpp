#include <iostream>
#include <vector>
#include <algorithm>

// 함수객체의 장점 1. Closure. 상태를 가지는 함수

bool foo(int n) { return n % 3 == 0; }

class IsDivide 
{
	int value;
public:
	IsDivide(int n) : value{n} {}

	bool operator()(int n) { return n % value == 0;}
};




int main()
{
	std::vector<int> v = { 1,2,6,5,4,3,7,8 };

	int k = 3;

	IsDivide f(k); // f 는 내부적으로 k를 보관합니다.
				   // f 는 함수 처럼 사용가능합니다.(단항함수)
				   
	bool b = f(6); // "6 % k == 0" 의 기능 수행

	auto p1 = std::find_if(v.begin(), v.end(),  ? );

}



