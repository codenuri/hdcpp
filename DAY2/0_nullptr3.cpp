// C에서 NULL 과 차이가 있나요? 
#include <iostream>

void foo(void* p) { std::cout << "void*" << std::endl; }
void foo(int n)   { std::cout << "int"  << std::endl; }

void goo(char* p) { std::cout << "char*" << std::endl; }

int main()
{
	foo(0); // int
	foo((void*)0); // void*    nullptr이 없다면 이렇게 해야합니다.

// 현재 C++ 컴파일러가 제공하는 NULL 은 아래와 같습니다. 
// 아래 코드는 이미 C++ 표준에 있습니다. 아래 코드 주석으로 막아도 됩니다.
/*
#ifdef __cplusplus	// 모든 C++컴파일러가 제공하는 매크로
	#define NULL 0

#else
	#define NULL  (void*)0		
#endif 
*/
	foo(NULL); // 결국 C++에서는 0이므로 int 호출..
	
	goo(NULL); // C 언어,  void* => char* 로의 암시적 변환 허용. ok
			   // C++언어, void* => char* 로의 암시적 변환 허용안함. error

}
//				정체		
// NULL			매크로(C++에서는 결국 0)
// nullptr		키워드(컴파일러가 인식하는 미리 약속된 문자)

// NULL로는 위와 같은 문제를 해결할수 없다.!
// 그래서, nullptr 을 만들었다.. 