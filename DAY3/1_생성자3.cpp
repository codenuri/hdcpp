// 5_생성자3 - 78page ~
#include <iostream>

class Point
{
	int x;
	int y;
public:
	// 핵심 1. 사용자가 "생성자를 한개도 만들지 않으면"
	//        컴파일러가 "디폴트 생성자"를 제공합니다.
	// 디폴트 생성자 : 인자가 없는 생성자
	// 
	Point()             { x=0; y=0; std::cout << "Point()"         << std::endl; } // 1
	Point(int a, int b) { x=a; y=b; std::cout << "Point(int, int)" << std::endl; } // 2
};

int main()
{
	Point p1;			// 1번 생성자 호출
	Point p2(1, 2);		// 2번 생성자 호출

	// 핵심 2. C++11 부터는 객체 생성시 {} 도 사용가능
	Point p3{ 1,2 };	// 2번 생성자 호출
	Point p4 = { 1,2 }; // 2번 생성자 호출

	// 핵심 3. 객체생성시 반드시 생성자가 호출되어야 합니다.
	Point arr1[5];		// 1번 생성자 5회 호출

	Point arr2[5] = { {1,2},{2,3} }; // 2번 생성자 2회, 1번 생성자 3회 호출



	Point* p;  // 객체 생성이 아닌 포인터 변수 선언. 생성자 호출 안됨.

	// 아래 코드는 "Point객체"의 생성이 아니라
	// Point 타입의 크기(8byte) 만큼 메모리 할당한것
	// 생성자 호출 안됨.
	p = (Point*)malloc( sizeof(Point) ); 
	free(p); // 소멸자도 호출 안됨					


	// 아래 코드는 "Point의 객체를 동적메모리에 할당해 달라" 는 것
	p = new Point;  // 1번 생성자 호출
	delete p;

	p = new Point(1, 1);// 2번 생성자 호출
	delete p;			// 소멸자 호출
}

