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

	// 규칙 #2. 복사와 대입을 금지
	// => 컴파일러에게 복사생성자, 대입연산자를 만들지 말라고 요청
	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;	// C++11 함수 삭제 문법



	// 규칙 #3. 오직 한개의 객체만 생성해서 반환하는 static 멤버 함수
public:
	static Cursor& get_instance()
	{
		static Cursor instance;
		return instance;
	}
};
int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();

	std::cout << &c1 << std::endl;
	std::cout << &c2 << std::endl;

	// Cursor c3 = c1; // 일반 생성자가 아닌 "복사생성자" 호출
					// 이렇게 만드는 것도 막아야 합니다.
}


// 위 코드는 effective-c++ 의 저자인 "scott meyer" 가 처음 제안
// 그래서, "meyer's singleton" 이라고 하고

// C++로 만드는 싱글톤 중 "가장 좋은 코드" 로 알려진 코드
// => 간결, 안전, 성능 모두 최선

// policy base design 은 "modern c++ design" 책에서 소개
// => 안드레이 알렉산드레스큐
// => 2002년 발간



