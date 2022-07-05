// C에서 NULL 과 차이가 있나요? 
#include <iostream>

void foo(void* p) { std::cout << "void*" << std::endl; }
void foo(int n)   { std::cout << "int"  << std::endl; }

void goo(char* p) { std::cout << "char*" << std::endl; }

int main()
{
	foo(0); 
}