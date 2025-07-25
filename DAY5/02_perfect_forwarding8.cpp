#include <iostream>
#include <thread>
#include "chronometry.h"

void foo(int a, double d)
{
	std::cout << "start foo\n";

	std::this_thread::sleep_for(2s); // 2초간 대기

	std::cout << "end foo\n";
}

int main()
{
	chronometry(foo, 2, 2.3);
}
