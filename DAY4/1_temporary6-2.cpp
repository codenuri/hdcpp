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
	const std::string& s5 = max(std::string{"AA"}, 
								std::string{"BB"});

}