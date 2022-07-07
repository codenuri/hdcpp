// 상속1.cpp   132page ~
#include <iostream>
#include <string>

// 모든 사람이 가지는 공통의 특징을 먼저 설계 한다.
class Person
{
	std::string name;
	int age;
};

// 상속(inheritance)
// => 기존 클래스(타입)을 확장해서 새로운 타입을 만드는 문법
// => 대부분의(거의모든)객체지향 언어가 지원

// C++     : class Student : public Person 
// C#      : class Student : Person 
// Python  : class Student(Person)
// Java    : class Student extends Person 

// Person  : Base(기반) class,    Super class, Parent class
// Student : Derived(파생) class, Sub class,   Child class


class Student : public Person 
{	
	int    id;
};

class Professor : public Person
{	
	int    major;
};

int main()
{
	Student s;
	Professor p;
}


