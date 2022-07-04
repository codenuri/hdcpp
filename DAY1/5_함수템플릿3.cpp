#include <iostream>

template<typename T1, typename T2>
//? Add(T1 a, T2 b)	// ? 채워 보세요. C++진영에서 이런 코드를 만들고 싶었습니다.

//decltype(a + b) Add(T1 a, T2 b)	// 이때 사용하려고 decltype을 만들었습니다.
								// 그런데, 왜 에러일까요 ?

auto Add(T1 a, T2 b) -> decltype(a + b) // ok.. 컴파일 됩니다.
						// 이런 문제를 해결하기 위해 후위반환 타입 문법 등장
						// C++11 표기법
{
	return a + b;
}

// C++14 부터는 아래처럼 해도 됩니다.
// 이경우 return 문을 보고 컴파일러가 타입을 추론합니다.
// 그런데, return 문이 2개 이상이고 서로 다른 타입이면 
// 컴파일러는 추론할수 없습니다.
template<typename T1, typename T2>
auto Add2(T1 a, T2 b) 
{
	return a + b;

// 	return a == 0 ? a : b;  // 이런코드라면 추론 안됩니다
}



int main()
{
	// 정확한 표기법
	std::cout << Add<int, double>(1, 2.2) << std::endl;  

	// 타입인자를 생략한 표기법
	std::cout << Add(1, 2.2) << std::endl;


//	a = 10;		// error. 왜 에러인가요 ? 변수를 선언전에 사용
//	int a = 0;	// 변수 선언
//	a = 20;		// ok. 변수 선언후 사용
			
}

