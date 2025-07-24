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
	void set_name(const std::string& n) { name = n; } 
	void set_name(std::string&& n)      { name = std::move(n); } 

	// setter(데이타를 멤버에 보관하는 것) 만 move 지원하면 됩니다.
	// 읽기만 하는 것은 const T& 한개면 됩니다.

	void print(const std::string& s)
	{
		// s 를 읽기만하고
		// s의 자원을 멤버 데이타에 보관안함
	}
};

int main()
{
	std::string s1 = "kim";
	std::string s2 = "lee";

	People p;


}








