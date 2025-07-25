#include <iostream>
#include <thread>
#include "chronometry.h"
using namespace std::literals;

int foo(int a, double d)
{
	std::cout << "start foo\n";
	std::this_thread::sleep_for(2s); // 2초간 대기
	std::cout << "end foo\n";
	
	return 100;
}
int main()
{
	int ret = chronometry(foo, 2, 2.3); // foo(2, 2.3)
}
