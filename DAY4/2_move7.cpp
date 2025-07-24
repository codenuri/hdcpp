#include <iostream>
#include <string>
#include <vector>

// 핵심 : Setter 만들기 #1

class People
{
private:
	std::string name;
	int age;
public:

	// 아래 코드는 
	// C++98 시절에는 "최선의 코드"
	// C++11 이후에는 "나쁘지는 않은 코드", 최선은 아님
//	void set_name(const std::string& n) { name = n; } // 항상복사

//	void set_name(const std::string& n) { name = std::move(n); } 
										// 역시 항상복사, n 은 const!


	// C++11 이후의 최선의 코드
	// => 2개의 setter 를 만들어야 합니다
	void set_name(const std::string& n) { name = n; } 
	void set_name(std::string&& n)      { name = std::move(n); } 
};

int main()
{
	std::string s1 = "kim";
	std::string s2 = "lee";

	People p;

	p.set_name(s1);
	p.set_name(std::move(s2));	

	std::cout << s1 << std::endl; // "kim"
	std::cout << s2 << std::endl; // ""


	// C++ 표준 vector
	std::vector<std::string> v;
	v.push_back( s1 );
	v.push_back( std::move(s1) );
}








