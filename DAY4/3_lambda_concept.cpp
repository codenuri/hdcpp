int add(int a, int b) { return a + b;}

void foo( int(*)(int, int) )
{

}

int main()
{
	foo( &add );
	
	// 람다 표현식 문법 ( C++11)
	// => 함수 이름(주소)가 필요한 위치에 함수 구현을 전달하는 문법
	// => "익명의 함수" 를 만드는 문법

	// [] : lambda introducer
	//      lambda expression 이 시작됨을 알리는 기호
	foo( [](int a, int b) { return a + b;}    );

	// Python, C#, Java, Swift, Rust 등 현대의 모든 언어가 지원하는 문법
}