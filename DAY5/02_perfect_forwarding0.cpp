#include <iostream>

// "완벽한 전달" 기술을 배우기 위한 사전 지식

void foo(int& a)		{ std::cout << "1. int&" << std::endl; }
void foo(int&& a)		{ std::cout << "2. int&&" << std::endl; }

int main()
{
	int n = 10;
	foo(n);		// int&
	foo(10);	// int&&

	int& r1 = n;
	foo(r1);	// 1. int&


	int&& r2 = 10;
	foo(r2);	// 1. int& 입니다!!!

	foo(static_cast<int&&>(r2));	// 2. int&& 호출

	// r2 가 int&& 타입 인데 ? 다시 int&& 타입으로 캐스팅 ?? 
	// 같은 타입아닌가요 ?
	
	// static_cast 문법 : 표준문서에 명시되어 있습니다.

	// static_cast<임의타입>  : 타입 캐스팅
	// static_cast<임의타입&> : 타입 캐스팅
	// static_cast<임의타입&&>: 타입 캐스팅이 아닌 value 캐스팅
	//							lvalue => rvalue 로 변경하는 캐스팅
	//							rvalue => lvalue 캐스팅은 안됩니다.



}



// Point pt{1,1};
// "타입과 value category(lvalue, rvalue) 를 잘 구별하세요"
//					type		value category
// n				int			lvalue
// 10				int			rvalue

// pt				Point		lvalue
// Point{1,1}		Point 		rvalue
// r1				int&		lvalue
// r2				int&&		lvalue

// foo(int&)  : int& 타입을 받겠다는게 아니라 lvalue 받겠다
// foo(int&&) : int&& 타입을 받겠다는게 아니라 rvalue 받겠다





