#include <iostream>
#include <vector>

class Person
{
	std::string name;
	int age;
public:
	Person(const std::string& s, int a) : name(s), age(a) {}
};

// 핵심 1. Person 처럼 디폴트 생성자가 없는 클래스도 많이 있습니다.
//     2. 이때, Person 으로 부터 상속받는 클래스를 만들수 있어야 합니다.

class Student : public Person
{
	int id;
public:
	// 사용자 코드				// 컴파일러가 변경한것
//	Student(int n) : id(n) {}	// Student(int n) : Person(), id(n) {}

	// Student 제작자는 Person 에 디폴트 생성자가 없는 것을 알고 있어야 한다.
	// 그래서, Person에 전달할, "이름, 나이"도 인자로 받아서 전달해야 한다.
	Student(const std::string& name, int age, int n) 
		: Person(name, age), id(n) {}
};

int main()
{
//	Person p1;	// 이 코드가 되게 할까요 ? 안되게 할까요 ?
				// error. Person 은 디폴트 생성자가 없습니다.
	Person p2("kim", 10); // ok

//	Student s1(99); // error. 학생이 "이름", "나이" 초기화가 안된다.

	Student s2("kim", 20, 99); // ok
}



