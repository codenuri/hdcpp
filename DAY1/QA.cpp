// QA
template<typename T> 
void foo(T a)
{
}
int main()
{
	auto a1 = 1;	// int a1 = 1
	foo(1);			// foo(int arg) 함수 생성

	// 즉, 
	// auto a = 우변;    // auto 는 우변으로 타입이 추론됩니다.
	// T    a = 함수인자; // template 은 함수 인자로 타입이 추론됩니다.

	// 그런데, auto 와 template 의 타입이 추론되는 알고리즘은 동일합니다.
	
	// => auto 가 어떤 타입으로 추론되었는지는 조사하기 쉽지 않습니다.
	// => 템플릿 인자가 어떤 타입으로 추론되었는지는 알기는 쉽습니다.
	//    => "godbolt" 에 넣어보는것이 제일 정확 합니다.



	// auto를 통해 결정된 타입을 확인할 수 있는 방법도 있나요??
	const int c = 10;
	auto a2 = c;
	f2(c);
}