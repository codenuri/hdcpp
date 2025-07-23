#include <iostream>

// 싱글톤 : 오직 한개의 객체만 존재 하고, 
// 		   어디에서도 동일한 방법으로 접근 가능한 객체

// => 결국 전역변수 와 동일
// => 그런데, 전역변수는 좋지 않습니다.
// => 그래서, "싱글톤 패턴은 사용하지 말자" 라는 의견도 많이 있습니다.

class Cursor
{
	// 규칙 #1. private 생성자
private:
	Cursor() {}

	// 규칙 #2.

	// 규칙 #3. 오직 한개의 객체만 생성해서 반환하는 멤버 함수
	Cursor& get_instance()
	{
		static Cursor instance;
		return instance;
	}
};


int main()
{
	Cursor c1, c2;
}








