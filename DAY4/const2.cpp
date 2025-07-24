// const member function 문법은
// "선택이 아닙니다. 필수 입니다."
// => 멤버 데이타를 변경하지 않은 모든 멤버 함수 getXXX() 는 반드시
// => 상수 멤버함수로 해야 합니다.

class Rect
{
	int x = 0, y = 0, w = 0, h = 0;	
public:
//	int get_area() { return w * h;} // 틀린 코드
	int get_area() const { return w * h;} // ok
};

//void foo( Rect rc)      // call by value : 복사본 오버헤드
//void foo( Rect& rc) // 이렇게 하면 "임시객체" 받을수 없습니다.
void foo( const Rect& rc) // 좋은 코드
{
	int n = rc.get_area(); // 호출되려면 get_area()는 반드시
							// 상수 멤버함수 이어야 합니다.
}

int main()
{
	Rect r;					// 상수객체 아님
	int n = r.get_area();	// OK
	foo(r);
}