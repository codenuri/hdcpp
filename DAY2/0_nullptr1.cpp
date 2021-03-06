// 11_nullptr1.cpp    54 page

int main()
{
	// 0의 정체 : 0은 정수(int)지만 포인터로 암시적 형변환된다.
	//         => 컴파일러에 의해 특별하게 처리됩니다.
	int  n1 = 0; // ok
	int* p1 = 0; // ok

	int* p2 = 10; // error. 10도 정수지만, 포인터로 암시적 변환 안됩니다.
	int* p3 = n1; // error. n1에는 0이 있지만 안됩니다.
					//      literal 0만 포인터로 변환되고, 
					//      0을 가진 정수형 변수는 변환 안됩니다.

	// 위와 같은 사실이 많은 혼란이 있고,
	// 특정한 경우에 문제가 됩니다.
	// 그래서, C++11 에서 포인터 0을 나타내는 새로운 키워드가 등장
	int* p4 = nullptr; // ok 
	int  n2 = nullptr; // error. nullptr은 포인터 초기화 에만 사용가능
	

}
