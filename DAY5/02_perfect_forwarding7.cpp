#include <iostream>

void f0() {}
void f1(int a) {}
void f2(int a, double d) {}
void f3(int a, double d, int& r) { r = 200;}

template<typename F, typename ... T>
void chronometry(F f, T&& ... arg)
{
	f( std::forward<T>(arg)... ); 	
}

int main()
{
	int n = 3;
	chronometry(f0); 	// f0()
	chronometry(?);		// f1(10)	
	chronometry(?);		// f2(10, 3.4)
	chronometry(?);		// f3(10, 3.4, n)

	std::cout << n << std::endl; // 200
}





