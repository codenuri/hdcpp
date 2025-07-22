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

    static char to_upper(char ch)
    {
        return std::toupper((unsigned char) ch);
    }
 
    static bool eq(char c1, char c2)
    {
        return to_upper(c1) == to_upper(c2);
    }
 
    static bool lt(char c1, char c2)
    {
         return to_upper(c1) < to_upper(c2);
    }
 
    static int compare(const char* s1, const char* s2, std::size_t n)
    {
        while (n-- != 0)
        {
            if (to_upper(*s1) < to_upper(*s2))
                return -1;
            if (to_upper(*s1) > to_upper(*s2))
                return 1;
            ++s1;
            ++s2;
        }
        return 0;
    }
 
    static const char* find(const char* s, std::size_t n, char a)
    {
        const auto ua{to_upper(a)};
        while (n-- != 0) 
        {
            if (to_upper(*s) == ua)
                return s;
            s++;
        }
        return nullptr;
    }	
};

using ci_string = std::basic_string<char, MyTrait>;

int main()
{
//	std::string s1 = "ABCD";
//	std::string s2 = "abcd";
	ci_string s1 = "ABCD";
	ci_string s2 = "abcd";

	// 아래 결과 예측해 보세요 ( 0 ? 1);
	std::cout << (s1 == s2) << std::endl;
}