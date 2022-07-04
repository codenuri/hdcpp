// 3_변수6.cpp   25 page 

struct Point
{
	int x, y;
};
int main()
{
	Point pt = { 1,2 };

	// 구조체형 변수에서 값을 꺼내는 일반 적인 방법
	int x = pt.x;
	int y = pt.y;

	// C++17 부터는 한줄로 모든 멤버 값을 꺼낼수 있습니다.
	// "structural binding" 이라는 문법
	auto [a1, a2] = pt; // auto a1 = pt.x
						// auto a2 = pt.y
	
	int[b1, b2] = pt; // error. auto 만 가능합니다.

	auto [c1, c2, c3] = pt; // error. 갯수가 같아야 합니다.
							// 많거나 적으면 안됩니다.

	int arr[3] = { 1,2,3 };

	auto [d1, d2, d3] = arr; // 구조체 뿐 아니라 배열도 됩니다.

}






// 빌드 에러 확인 되신 분들은 "교재 5page" 잠깐 와 보세요..

// g++, clang++ 최신 버전, visual studio 2017 ~ 2022
// => C++14을 기준으로 컴파일 합니다.
// => C++17, C++20 을 사용하려면 컴파일러 옵션 필요

// g++ 소스이름.cpp -std=c++17        -std=c++20

// visual C++ : /std:c++17, /std:c++20, /std:c++latest
// 
// vs2019,2022 : 