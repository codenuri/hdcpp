#include <iostream>
#include <string>
#include <vector>

// move 개념

int main()
{
	std::string s1 = "to be or not to be";
	std::string s2 = "to be or not to be";

	std::string s3 = s1; // 문자열 깊은 복사
	std::string s4 = std::move(s2);
						// s2의 자원을 s4로 이동
						// 이후 코드에서는 s2는 자원(문자열) 없습니다

	std::cout << s1 << std::endl; // "to be or not to be"

	// 자원을 손실한 s2에 대해서
	// => 사용해도 컴파일 에러 아닙니다.
	// => 하지만 객체 상태는 undefined 입니다.
	// => 대부분 표준 라이브러리는 사용가능하지만
	//    외부 클래스는 절대 사용하지 마세요
	
	// [참고] rust 에서는 컴파일 에러 입니다.
	std::cout << s2 << std::endl;


}

