#include <string>
#include <iostream>

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


int main()
{
	std::string s1 = "ABCD";
	std::string s2 = "abcd";

	// 아래 결과 예측해 보세요 ( 0 ? 1);
	std::cout << (s1 == s2) << std::endl;
}