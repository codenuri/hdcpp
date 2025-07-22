#include <string>
#include <iostream>

/*
template<typename T, // char ? wchar_t ?, utf-8....
	     typename Trait = std::char_traits<T>, // 문자(열) 비교 정책클래스
		 typename Alloc = std::allocator<T>>   // 메모리 할당 정책
class basic_string 
{
public:
	bool operator==(const std::basic_string& other)
	{
		return Trait::compare(this.buff, other.buff);
	}
};
using string = std::basic_string<char>;
using wstring = std::basic_string<wchar_t>;
*/
// 비교 정책 클래스는 만들어야 하는 약속된 함수가 많습니다.
// => C++ 표준 클래스에서 상속받아서 모든 조건을 만족하고
// => 변경하고 싶은 것만 다시 작성
struct MyTrait : public std::char_traits<char>
{
	// cppreference.com 에서 char_traits 검색
};

using ci_string = basic_string<char, MyTrait>;

int main()
{
//	std::string s1 = "ABCD";
//	std::string s2 = "abcd";
	ci_string s1 = "ABCD";
	ci_string s2 = "abcd";

	// 아래 결과 예측해 보세요 ( 0 ? 1);
	std::cout << (s1 == s2) << std::endl;
}