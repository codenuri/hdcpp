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
			// => 클래스에서 약간의 차이가 있는데, 내일 배우게 됩니다.

	int n4 = 3.4;		// ok.. 하지만 좋지 않다.!!

	int n5{ 3.4 };		// error. prevent narrow
	int n6 = { 3.4 };	// error

	char c1{ 500 };		// error. 1byte에 500을 담을수 없다.		
				
}


