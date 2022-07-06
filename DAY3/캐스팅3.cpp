
// C++ 은 용도별로 사용하기 위해 "4개"의 캐스팅 방법 제공합니다.(C++98)
#include <iostream>
#include <cstdlib>

// static_cast : 위험하지 않고, 꼭 필요한 캐스팅만 허용
//				 void* => 다른 타입* 허용
//			     상속관계 타입 캐스팅도 허용
//				그외는 대부분 실패

// reinterpret_cast : 서로 다른 타입의 주소 캐스팅의 용도로만 사용

int main()
{
	// void* => int* 변환
	int* p1 = (int*)malloc(20);					// ok
	int* p2 = static_cast<int*>(malloc(20));	// ok

	// int* => double* 변환
	int n1 = 0;
	double* p3 = (double*)&n1;				// ok
	double* p4 = static_cast<double*>(&n1);	// error
	double* p5 = reinterpret_cast<double*>(&n1); // ok

	
}



