#include <iostream>

struct Point
{
	int x, y;
};
int main()
{
	// 20page - 중요한 변화.!
	int n = 10;
	int x[3] = { 1,2,3 };
	Point p1 = { 1,2 };

	// C++11 "일관된 초기화(uniform initialization)" 이라는 문법
	// "중괄호 초기화(brace init)" 이라고도 합니다.
	int n2 = { 10 };
	int x2[3] = { 1,2,3 };
	Point p2 = { 1,2 };

	// =이 없어도 됩니다.
	int n3{ 10 };
	int x3[3]{ 1,2,3 };
	Point p3{ 1,2 };

	// direct initialization(직접 초기화) : = 없는 초기화
	// copy   initialization(복사 초기화) : = 있는 초기화
}


// 안들리시는분은 다시 접속확인해 보세요
