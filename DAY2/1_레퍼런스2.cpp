// 1_레퍼런스2
#include <iostream>
// 43 page

void inc1(int n)  { ++n; }
void inc2(int* p) { ++(*p); }
void inc3(int& r) { ++r; }

int main()
{
	int a = 1, b = 1, c = 1;

	inc1( a ); // call by value, a증가 실패 

	inc2(&b ); // call by pointer, b증가 성공!

	inc3( c ); // call by reference, c증가 성공

	std::cout << a << std::endl; // 1
	std::cout << b << std::endl; // 2
	std::cout << c << std::endl; // 2
}
// call by pointer 와 call by reference 는 
// 결국, 원본을 수정(out parameter) 할수 있다는 점에서
// 유사 합니다.
// 그런데, reference 가 좀더 편리하고 안전합니다.

void f1(int* p)
{
	if (p != nullptr)	// 포인터는 이렇게 조사하는
	{					// 경우가 많습니다.
		*p = 10;
	}
}
void f2(int& r)
{
	r = 10; // 레퍼런스는 대부분 이렇게 그냥 사용합니다.
}

// 레퍼런스로 사용했다라고 명시하는 표기법이 별도로 있을까요 ?
// => 없습니다. 함수 선언을 보고 확인해야 합니다.
// => 또는, "out parameter" 라는 설명(문서화)을 할수도 있습니다.