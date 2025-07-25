// 함수 인자로
// int&	 : int 타입의 lvalue 만 받을수 있다.
// int&& : int 타입의 rvalue 만 받을수 있다.
// T&    : 임의 타입의 lvalue 만 받을수 있다.
//		  => T에 int&, int&& 로 결정되어도 
//	      => int& &, int&& & 이므로 최종적으로는 lvalue reference 
//--------------------------------------------------------------
// T&& : 임의 타입의 lvalue, rvalue 모두 받을수 있다.

// 인자가 T&& 라면 특별한 추론 규칙이 적용된다.
// 인자로 lvalue(n) 를 보내면 : T = int&, T&& = int& && => int&, f4(int&) 
// 인자로 rvalue(3) 를 보내면 : T = int,  T&& = int&&            f4(int&&)

// "모두 받을수 있다" 는 의미는
// => lvalue reference 버전과 rvalue reference 버전의 함수를 "각각 생성"한다는것
// => 생성된 함수는 "call by value" 가 아닌 "call by reference"!!

// C++11 초창기에 T&& 에 대한 이름이 없었습니다.
// => effective 책에서 "universal reference" 라는 이름 제안
// => 그런데, 나중에 표준위원회에서 "forwarding reference" 로 결정
//    이기술이 주로, "인자 포워딩" 에 사용되기때문에 붙인 이름

template<typename T> void f4(T&& a)
{
}
int main()
{
	int n = 3;

	f4(3);	// T = int 로 결정, 인자는 T&& 이므로,  f4(int&& a) 로 생성
			// "3" 은 rvalue 이므로 f4으로 전달 가능
			// ok

	f4(n);  // 1. T = int,  T&& = int&&, f4(int&& a) 라면 f4(n) error 
			// 2. T = int&, T&& = int& && => int&, f4(int&) 라면 f4(n) 은 에러아님
			// T&& 일때의 경우만 2번으로 추론

	f3(n); // T = int 로 추론		
	f4(n); // T = int& 로 추론
}


