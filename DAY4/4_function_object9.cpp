#include <algorithm>

int main()
{
	int n1 = std::max(1, 2); // C++98 표준 함수(템플릿) 입니다.

	int n2 = std::ranges::max(1,2); // C++20 에서 추가
									// 함수 객체 입니다
	int n3 = std::ranges::max.operator()(1,2);									

	// g++ 소스이름.cpp -std=c++20	
}

// Rust : "모든 함수는 다른 타입이다."

// vec.sort_by(cmp1);  // cmp1, cmp2 가 rust로 만든 일반함수 라면
// vec.sort_by(cmp2);  // 인라인 치환됨

// 그런데, signature 가 동일한 함수는
// 같은 타입의 함수 포인터로 변환 된다.
// vec.sort_by(cmp1 as fn(i32, i32)->i32 );
// vec.sort_by(cmp2 as fn(i32, i32)->i32 ); // 치환 안됨 

