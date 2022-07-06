// 6_초기화리스트1    85page ~
#include <iostream>
#include <string>

class Person
{
	std::string name;
	int age;
public:
	Person(const std::string& n, int a)
	{
		name = n;
		age = a;
	}
};
int main()
{
	Person p1("kim", 10);
}




