// 5_생성자1.cpp
#include <iostream>
#include <string>

class Person
{
private:
	std::string name;
	int  age;
public:

	// 생성자는 2개 이상 만들어도 됩니다.(인자가 다르면)
	Person(const std::string& n, int a)
	{
		std::cout << "생성자 호출됨" << std::endl;
		name = n;
		age = a;
	}	
	Person()
	{
		name = "unknown";
		age = 0;
	}

	// 소멸자 : "~클래스이름" 모양의 함수
	//			반환값과 인자가 없다. 오직 한개만 만들수 있다.
	//		    객체가 파괴 될때 호출.

	// 생성자는 "객체 초기화"를 위해 사용되는데, 
	// 소멸자는 언제 왜 사용하나요 ?
	// => 필요없으면 만들필요 없습니다. 필요한 경우만 만드세요
	// => 다음시간예제 참고.. 
	~Person() { std::cout << "소멸자" << std::endl; }
};


int main()
{
	// 모든 객체는 생성될때 생성자가 호출됩니다.
	Person p1("kim", 28); 
	Person p2;

} //<== p2, p1 파괴. 소멸자 호출됨



