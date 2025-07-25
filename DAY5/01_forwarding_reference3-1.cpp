// 함수 인자로
// int&	 : int 타입의 lvalue 만 받을수 있다.
// int&& : int 타입의 rvalue 만 받을수 있다.

// T& : 임의 타입의 lvalue 만 받을수 있다.
//		=> T에 int&, int&& 로 결정되어도 
//	    => int& &, int&& & 이므로 최종적으로는 lvalue reference 

template<typename T> void f3(T& a)
{
}

int main()
{
	int n = 3;
	f3(n);  // 함수인자인 "n" 으로 컴파일러가 T 타입 결정
			// T = int 으로 결정
			// 생성된 함수 "f3(int& a)"
			// n 은 lvalue 이므로 ok

	f3(3);	// T = int 로 결정, f3(int& a) 로 생성
			// "3" 은 rvalue 이므로 f3으로 전달 안됨
			// error
}


