#include <iostream>

int main()
{
	int n1 = 10;
	int n2 = std::move(n1);

	int* p1 = new int;
	int* p2 = std::move(p1);
}




