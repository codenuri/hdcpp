int main()
{
	int v1 = 10;

	// QA. f1는 변경할수 없으므로 const로 하면 안되나요?
	// => 문제될때가 있습니다

	const auto f1 = [](int a) { return a + v1;};

	f1(10); // ok

	
	const auto f2 = [](int a) mutable { v1 = 10; return a + v1;};

	f2(10); // error.
			// f2는 상수 객체인데. 
			// mutable 람다는 () 연산자가 non-const
			// 호출할수 없음.

	
}