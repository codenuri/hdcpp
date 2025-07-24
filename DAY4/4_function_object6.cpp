#include <iostream>

// #1. C/C++ 에서 일반 함수는 자신만의 타입이 없다.
//     signature 가 동일한 모든 함수는 같은 타입이다.

// #2. 함수객체는 자신만의 타입이 있다.
//     signature 가 동일한 모든 함수객체는 다른 타입이다.

struct Less    { inline bool operator()(int a, int b) const { return a < b; } };
struct Greater { inline bool operator()(int a, int b) const { return a > b; } };

//----------------------------------------------------------
// 비교 정책을 변경할수 있는데, 비교정책의 인라인 치환도 가능한 함수
// => "template + 함수객체" 로 만드는 기술
// => 예전에는 C++만 가능했는데, Rust 도 거의 동일한 개념지원
template<typename T>
void Sort(int* x, int sz , T cmp )
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = i + 1; j < sz; j++)
		{
			if ( cmp(x[i], x[j]) == true )	
				std::swap(x[i], x[j]);
		}
	}
}

int main()
{
	int x[] = { 1,3,5,7,9,2,4,6,8,10 };

	Less    f1; f1(5, 3); Sort(x, 10, f1);
	Greater f2; f2(5, 3); Sort(x, 10, f2);
}