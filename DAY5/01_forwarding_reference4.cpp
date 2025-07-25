struct Point
{
	int x, y;
	Point(int a, int b) : x(a), y(b) {}
};

// lvalue 와 rvalue 를 모두 받는 함수 만들기

// 방법 #1. call by value
// 특징 : 복사본 생성
// void foo(Point pt) {}

// 방법 #2. call by const lvalue reference
// 특징 1. 복사본 없음
//      2. 상수성(const) 추가. 
void foo(const Point& pt) {}

//--- 여기 까지는 C++98 기술

// 방법 #3. 2개의 foo 제공
// => 복사본 없고, 상수성 추가 안됨.
void foo(Point&  pt) {}
void foo(Point&& pt) {}


// 방법 #4. T&& 사용하면 "방법#3" 을 자동으로 생성할수 있다.
// => Point 타입뿐 아니라 모든 타입에 대해서 자동생성
template<typename T>
void foo(T&& pt) 
{

}



int main()
{
	Point pt(0, 0);

	// foo 함수에 lvalue 와 rvalue를 모두 보내고 싶다.
	foo(pt);
	foo(Point{0,0});
}
