// 1_temporary6-1.cpp

#include <string>


template<typename T>
const T& max( const T& a, const T& b)
{
	return a < b ? b : a;
}

int main()
{
	std::string s1 = "AAA";
	std::string s2 = "BBB";

	std::string s3 = max(s1, s2); // max 의 반환값은 결국
								  // s2의 참조, 
								  // 그런데 왼쪽이 s3 객체 생성

	const std::string& s4 = max(s1, s2); // s4 가 결국 "s2의 별명"
										 // 아무 문제 없는 코드		
										 
	// 핵심 : 아래 코드 될까요 ?
	// => 임시객체의 수명 연장은
	// => 최초 연결되는 reference 에 의해서 만 가능
	// => 2번 연장될수 없다.
	// => 따라서 s5 를 사용하면 파괴된 객체를 사용하게 된다
	// => dangling reference
	// => cppreference.com 에서 std::max 에서 Note"" 항목 읽어 보세요
	// => 
	const std::string& s5 = max(std::string{"AA"}, 
								std::string{"BB"});

	// 여기서 s5 사용...
	// 구글 에서 "std::max" 검색후 1번째 링크 - cppreference.com 으로 연결
	// std::max() 설명의 "Notes" 부분

	// Capturing the result of std::max by 
	// reference produces a dangling reference 
	// if one of the parameters is a temporary and 
	// that parameter is returned:
	int n = -1;	// n     : lvalue
				// n + 2 : 결과값은 1  이름이 없는 연산의 결과 rvalue

	const int& r = std::max(n + 2, n * 2);
}