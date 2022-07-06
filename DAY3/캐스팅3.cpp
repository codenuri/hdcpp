
// C++ 은 용도별로 사용하기 위해 "4개"의 캐스팅 방법 제공합니다.(C++98)
#include <iostream>
#include <cstdlib>

// static_cast : 위험하지 않고, 꼭 필요한 캐스팅만 허용
//				 

int main()
{
	int* p1 = (int*)malloc(20);
	int* p2 = static_cast<int*>(malloc(20));

	int n1 = 0;
	double* p3 = (double*)&n1;
	double* p4 = static_cast<double*>(&n1);
}