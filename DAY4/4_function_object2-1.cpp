#include <iostream>
#include <vector>
#include <algorithm>

// 함수객체의 장점 1. Closure. 상태를 가지는 함수

// 일반 함수 : 동작은 있지만 상태가 없습니다.
// 			  그래서, 함수 수행중에 생성된 결과를 보관 할수 없습니다.

bool foo(int n) 
{ 
	return n % 3 == 0; 
}

// 함수 객체 : 동작 뿐 아니라 상태를 가지게 됩니다.
//			  "멤버데이타" 가 있다는 의미
//			  "상태를 가지는 함수" 라는 용어도 사용됩니다.

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

	auto p1 = std::find_if(v.begin(), v.end(), f );	// "단항함수 + k"를 전달

	auto p2 = std::find_if(v.begin(), v.end(), IsDivide{k} );
									// "단항 함수 + 지역변수 k"
									// 를 같이 전달하는 모습
}

// 클로져(Closure) 라는 용어
// => 자신이 속한 문맥(main함수)의 지역벼수를 캡쳐 할수 있는 능력을
//    가진 함수

// 일반 함수 : Closure 가 될수 없습니다.
// 함수 객체 : Closure 가 될수 있습니다.

// Rust 등 일부 언어는 "람다 표현식" 이라는 용어 대신 "클로져" 사용
// 클로져 용어 자체는 "모든 언어의 공통적인 용어"


