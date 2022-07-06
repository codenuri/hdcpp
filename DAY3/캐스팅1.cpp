// 캐스팅1 - 48 page
#include <iostream>

int main()
{
	std::cout << sizeof(char) << std::endl;
	std::cout << sizeof(int)  << std::endl;

	// 핵심 1. char  와 int  타입의 크기는 다르지만
	//		  char* 와 int* 타입의 크기는 동일하다.
	//		  모든 포인터 변수의 크기는 동일하다.( 32bit : 4byte, 64bit : 8byte)
	std::cout << sizeof(char*) << std::endl;
	std::cout << sizeof(int*)  << std::endl;


	// 핵심 2. 변수 주소를 다른 타입의 포인터 변수에 담는 코드...
	int n1 = 10;
	int*  ip = &n1;
	char* cp = &n1;

}




