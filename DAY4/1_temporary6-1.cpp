// 1_temporary6-1.cpp

#include <string>

// max 를 만들어 봅시다.
// 인자 : lvalue, rvalue 모두 받아야 합니다.
// => const reference!!
// 반환 타입 : 임시객체를 만들지 않기 위해 const T&

// 아래 max 가 C++ 표준의 std::max 와 동일 합니다.
template<typename T>
const T& max( const T& a, const T& b)
{
	return a < b ? b : a;
}

int main()
{
	std::string s1 = "AAA";
	std::string s2 = "BBB";

	std::string s3 = max(s1, s2);
//					max(2, 1);

}