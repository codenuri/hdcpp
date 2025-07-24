
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

// 람다표현식을 사용하면 위 클래스 쉽게 만들수 있습니다


int main()
{
	std::vector<int> v = { 1,2,6,5,4,3,7,8 };

	int k = 3;

	auto p1 = std::find_if(v.begin(), v.end(),

				[k](int n) { return n % k == 0;} );

}

// 람다표현식은 "익명의 함수객체를 만드는 표현식이다."
//				익명의 함수객체를 지역변수를 캡쳐할수 있다(closure)

// cppreference.com 에서 왼쪽 중간쯤 "expression" 선택
// 나타나는 페이지에서 중간쯤 "lambda expression" 선택
// 나타나는 페이지에서 위에 정의 읽어 보세요