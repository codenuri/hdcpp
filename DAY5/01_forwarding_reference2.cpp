int main()
{
	int n = 10;


	int *p = &n;
	int* *pp = &p;	// ok. 포인터의 포인터를 만들수 있습니다

	int& r = n;
//	int& &rr = r;	// error. reference 의 reference 는 만들수
					//		  없습니다.

	// 핵심
	// 1. reference 의 reference 를 직접 코딩으로 만들수 없다.
	// 2. 타입추론이나 type alias 사용시는 "reference 의 reference"
	//    는 에러가 아니다.
	// 3. reference collpasing 규칙
	// => 양쪽 모두 && 인 경우만 &&
	using LREF = int&; 
	using RREF = int&&;

	// reference collapsing
	LREF& r3 = n;		// int&  &		=> int&
	RREF& r4 = n;		// int&& &		=> int&
	LREF&& r5 = n;		// int&  &&		=> int&
	RREF&& r6 = 3;		// int&& &&		=> int&& 
}

template<typename T> void foo(T a)
{
	T& r = a; 	// int& & r = a
				// int& r = a;
}
foo<int&>(n);




