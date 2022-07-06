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
	int*  ip = &n1; // ok..

//	char* cp = &n1; // 어차피 모든 타입의 주소의 크기는 같으므로
					// 물리적으로는 문제 없다. 그런데,
					// C언어   : 에러는 아닌데, 경고 정도는 발생
					// C++언어 : 컴파일 에러

	// 경고(C) 나 에러(C++)을 없애려면 캐스팅 하면 됩니다.
	char* cp = (char*)&n1; // ok


	// 핵심 3. 왜 변수를 다른 타입 포인터에 보관하나요 ??

	int n2 = 0x11223344;
	int*  p1 = &n2;
	char* p2 = (char*)&n2;

	printf("%d\n", *p1);
	printf("%d\n", *p2);
					

}




