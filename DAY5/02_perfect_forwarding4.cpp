#include <iostream>

void hoo(int&& arg) {} 

/*
template<typename F>
void chronometry(F f, int& arg)
{
//	f(arg); 
	f(static_cast<int&>(arg)); 	// int& 를 int& 로 캐스팅 
								// 아무 일도 하지않은 필요 없는 캐스팅
								// 하지만 있어도 상관없고, 컴파일시 제거
								// 왜 ? : 아래 함수와 동일하게 만들기위해
}

template<typename F>
void chronometry(F f, int&& arg)
{
	f(static_cast<int&&>(arg)); 
}
*/
// T&& 기술을 사용하면 위 2개의 함수를 자동생성 할수 있습니다.
// 또한, int 뿐 아니라 모든 타입에 대해서 위와 같은 2개 버전 함수 생성
template<typename F, typename T>
void chronometry(F f, T&& arg)
{
	f(static_cast<T&&>(arg)); 
}

int main()
{
	int n = 3;
	chronometry(foo, 10); 	// T = int, T&& = int&&
							// chronometry(F, int&&)
							// => static_cast<int&&>(arg)
							
	chronometry(goo, n);	// T = ? T&& = ?
							// chronometry(F, ?)
							// => static_cast<?>(arg)
}

// foo, goo 복사해오세요



