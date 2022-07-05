// 함수 만들때 인자를 받는 방법 
// => 특별한 이유 아니면 무조건 아래 처럼 하세요

// A. 함수로 전달된 변수의 값을 수정하는 경우
// 1. 포인터도 좋고		  : void inc(int* p)
// 2. reference도 좋습니다. : void inc(int& r)


// B. 함수로 전달된 변수의 값을 수정하는 않는 경우

// 1. primitive 타입 : call by value로 하세요
//    => void f1(int n)
//    => primitive 타입 : 언어자체가 내장하고 있는 타입(int, double, char)

// 2. user define 타입(구조체, 클래스) : const reference로 하세요
//    => void f2(const Rect& r)

