// QA
template<typename T> 
void foo(T arg)
{
}

int main()
{
	auto a1 = 1;
	foo(1);

	// auto를 통해 결정된 타입을 확인할 수 있는 방법도 있나요??
	const int c = 10;
	auto a2 = c;
	f2(c);
}