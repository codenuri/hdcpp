#include <iostream>


void foo(int n)    { std::cout << "int" << std::endl; }
void foo(double d) { std::cout << "double" << std::endl; }
void foo(bool b)   { std::cout << "bool" << std::endl; }
void foo(int* p)   { std::cout << "int*" << std::endl; }

int main()
{
	foo(0);   // int,     리터럴 0은 "정수(int)" 타입 입니다.
	foo(0.0); // double,  리터럴 0.0은 "실수(double)" 타입 입니다.
	foo(false );// bool     리터럴 false 은 "bool" 타입 입니다.
	foo(nullptr); // int*   리터럴 nullptr 은 모든 포인터로
					//		암시적 변환 됩니다.

	// 모든 리터럴은 타입이 있습니다.
	10;		// int
	3.4;	// double
	false;	// bool 
	nullptr;// std::nullptr_t  라는 타입입니다.

	int n = 10; // 처럼

	std::nullptr_t mynull = nullptr; // 이렇게도 가능합니다.
				// std::nullptr_t 타입은 모든 포인터 타입으로	
				// 암시적 형변환 됩니다.
				
	int* p1 = nullptr; // 그래서, 이 코드가 컴파일되는 것 입니다.
	int* p2 = mynull;  // 이 코드도 위와 동일합니다.

}


