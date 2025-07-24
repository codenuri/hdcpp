#include <algorithm>

int main()
{
	int n1 = std::max(1, 2); // C++98 표준 함수(템플릿) 입니다.

	int n2 = std::ranges::max(1,2); // C++20 에서 추가
									// 함수 객체 입니다
	int n3 = std::ranges::max.operator()(1,2);									
}

