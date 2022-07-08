#include <iostream>
#include <cstring>

// 복사 생성자가 왜.. 중요 합니까 ?
// => Point 타입같은 경우는 그냥 컴파일러 제공 버전 사용하면 됩니다.

// 그런데, 일부 클래스에서 컴파일러 제공 버전이 문제가 됩니다.
// => 아래 예제.. 

class Person
{
	char* name;
	int   age;
public:
	Person(const char* s, int a) : age(a)
	{
		name = new char[strlen(s) + 1];
		strcpy_s(name, strlen(s) + 1, s);
	}
	~Person() { delete[] name; }
};
int main()
{
	// 위 코드는 아래 한줄에 대해서는 문제 없습니다.
	Person p1("kim", 25);

	// 그런데, 아래 코드에서 문제가 됩니다.
	// runtime error
	Person p2 = p1; 
		//	=> 1. 이순간 복사 생성자 호출
		//	   2. 사용자가 복사 생성자를 만들지 않았으므로 컴파일러가 제공
		//     3. 컴파일러가 제공 버전은 포인터 변수에 대해서 주소를 복사하므로
		//		  얕은복사(shallow copy) 현상 발생
					
}