#include <iostream>
#include <string>
#include <vector>

// 왜 move 가 중요한가 ?

// 아래 코드는 복사에 의한 Swap
// => 느립니다
/*
template<typename T>
void Swap(T& a, T& b)
{
	T tmp = a; 
	a = b;
	b = tmp;
}
*/
// move 에 의한 swap
// => 위 swap 보다 아주 빠릅니다
// => 현재 C++ 표준 swap 은 아래 처럼 구현
template<typename T>
void Swap(T& a, T& b)
{
	T tmp = std::move(a); 
	a = std::move(b);
	b = std::move(tmp);
}

int main()
{
	std::string s1 = "to be or not to be";
	std::string s2 = "to be or not to be";
	Swap(s1, s2);
}

// move 에서 알아야 하는 것
// #1. swap, 버퍼 복사 등의 알고리즘 작성시
// => std::move() 를 사용하면 빨라집니다.
// => 쉬운편

// #2. string이 아닌 우리가 만든 클래스가 move 를 지원하려면 어떻게해야하는가?
// => 어렵고 복잡한 이야기..

// C++ 
s2 = s1; 			// 복사
s2 = std::move(s1);	// 이동

// 기본 정책 : 복사
// 이동은    : 선택

// 초보자(move몰라도)가 "swap" 작성 가능
// 최적화는 "고급 개발자 선택" - move 선택

// Rust
s2 = s1;         // 이동. 기본 정책
s2 = s1.clone(); // 복사는 선택

s4 = s3;  // s3는 이동됨. 더이상 사용 못함

// 여기서 s3 사용하면 컴파일 에러!!

// "기본은 이동이다." "복사가 정말 필요하면 clone() 사용해라 "
// => 성능우선시 정책. 