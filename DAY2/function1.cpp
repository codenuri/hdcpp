#include <iostream>
#include <algorithm>
#include <functional>
using namespace std::placeholders; // _1, _2, _3 ...

// 4항 함수
void foo( int a, int b, int c, int d)
{
    printf("%d, %d, %d, %d\n", a, b, c, d);
}

int main()
{
    foo(1, 2, 3, 4);   // 4항 함수..

    // std::bind : 함수의 인자를 특정값으로 고정한 새로운 함수 생성
    
    // 사용법 : std::bind(M항함수주소, M개 인자)

    auto f1 = std::bind(&foo, 1, 2, 3, 4);  // 4항 함수의 인자 4개를 모두 고정한
                                            // 0항 함수 만들기

    f1(); // foo(1,2,3,4);

    
    auto f2 = std::bind(&foo, 3, _1, 7, _2); // 4항 => 2항 함수 만들기

    f2(9, 4);   // foo(3, 9, 7, 4);



    // ? 채워 보세요
    auto f3 = std::bind(&foo, _3, 2, _1, _2 );

    f3(3, 7, 6); // 6, 2, 3, 7 나오게 해보세요

	// std::bind 반환값은
	// => std::bind()의 인자에 따라 다른 타입입니다.
	// => 그래서 auto 또는 std::function<>으로 만 받을수 있습니다.
	// => <functional> 헤더 와 using namespace std::placeholders 필요

	// _1, _2, _3 : placeholders 라고 합니다.
}

// 함수의 인자를 고정한 새로운 함수를 만들기
// => 객체지향 디자인 패턴에서는 특별히 패턴으로 분류해서 이름을 정하지 않지만

// => 하지만, 함수형 프로그래밍에서는 아주 널리 사용되는 패턴 입니다.
// => "Currying" 이라고 합니다.


// Python 의 function.partial() 이 이 역활을 합니다.