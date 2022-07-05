#include <iostream>
#include <cstring>   // C 문자열 함수
#include <string>    // C++ string 타입

// 26 page

int main()
{
	// C 언어 에서의 문자열 관리 방법
	char s1[] = "ABCD";
	char s2[5];

//	s2 = s1;	// 의도 : 문자열 복사
				// 결과 : 컴파일 에러..
//	strcpy(s2, s1); // 보안 이슈로 에러
	strcpy_s(s2, strlen(s1), s1);

//	if (s2 == s1) {} // 의도는 문자열이 같은가 ?
					 // 결과는 배열 주소 비교, false 
	if ( strcmp(s2, s1) == 0 ) {}

	//==========================================
	// C++은 "문자열 타입"을 사용하세요(정확히는 class로 만든 타입)
	std::string s3 = "abcd";
	std::string s4 = s3;

	s4 = s3 + "world"; // 덧셈도 가능

	if (s4 == s3) {} // 비교도 이렇게 사용가능

}


