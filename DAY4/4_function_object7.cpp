#include <iostream>
#include <algorithm>

inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }

struct Less { inline bool operator()(int a, int b) const { return a < b; } };
struct Greater { inline bool operator()(int a, int b) const { return a > b; } };

int main()
{
	int x[] = { 1,3,5,7,9,2,4,6,8,10 };
	
	// std::sort() 모든 인자가 템플릿 입니다.
	// => 인자의 타입을 결정해서 함수를 생성한다는 의미

	// #1. 비교 정책으로 일반 함수를 전달하는 경우

	// 장점 : 비교정책 함수 를 여러번 교체 해도 sort() 함수는 한개만 생성됨
	//		  코드 메모리 증가 안함

	// 단점 : 비교 정책 함수가 인라인 치환될수 없다.
	//		  느리다.

	std::sort(x, x+10, cmp1); // sort(int*, int*, bool(*)(int, int) ) 인 함수 생성
	std::sort(x, x+10, cmp2); // sort(int*, int*, bool(*)(int, int) ) 인 함수 생성 





	// #2. 비교 정책으로 함수 객체를 전달하는 경우

	// 장점 : 비교 정책이 인라인 치환된다.. 빠르다.

	// 단점 : 비교 정책을 교체한 횟수 만큼 "sort()" 생성
	//		  코드 메모리 증가

	Less f1;
	Greater f2;
	std::sort(x, x+10, f1); // sort(int*, int*, Less) 인 함수 생성
	std::sort(x, x+10, f2); // sort(int*, int*, Greater) 인 함수 생성

}
