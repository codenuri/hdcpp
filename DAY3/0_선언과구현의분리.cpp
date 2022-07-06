#include <iostream>

// 어제 소스에서 vector8.cpp 소스에서
// vector 클래스만 복사해 오세요

// class 만드는 방법
// 1. class 선언 안에 멤버 함수의 구현까지 넣는 방법
// 2. class 안에는 멤버 함수 선언만 넣고 멤버 함수 구현은 외부(.cpp)로 분리
// => 파일이름에 대한 제약은 없습니다.(클래스 이름과 달라도 상관없습니다.)

// 단, 템플릿의 경우는
// 모든 멤버 함수의 구현이 반드시 "헤더"안에 있어야 합니다.
// 멤버 함수 구현을 .cpp로 분리하지 마세요..




#include "vector.h"

int main()
{
	vector v1(5, 3);

	v1.at(0) = 10;
	v1.resize(10);
	
	std::cout << v1.at(0) << std::endl;
	std::cout << v1.size() << std::endl;

}
