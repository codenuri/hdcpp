// 4_함수4-1
#include <iostream>

template<typename T>
T square(T a)
{
	return a * a;
}

int main()
{
	printf("%p\n", &square); // 어떻게 될지 생각해 보세요

}