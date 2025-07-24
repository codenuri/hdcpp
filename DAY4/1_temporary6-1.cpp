// 1_temporary6-1.cpp

#include <string>

// max 를 만들어 봅시다.
template<typename T>
T max( T a, T b)
{
	return a < b ? b : a;
}

int main()
{
	std::string s1 = "AAA";
	std::string s2 = "BBB";

	std::string s3 = max(s1, s2);

}