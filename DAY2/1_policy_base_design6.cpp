#include <string>
#include <iostream>

int main()
{
	std::string s1 = "ABCD";
	std::string s2 = "abcd";

	// 아래 결과 예측해 보세요 ( 0 ? 1);
	std::cout << (s1 == s2) << std::endl;
}