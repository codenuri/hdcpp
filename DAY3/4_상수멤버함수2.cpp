// 상수 멤버 함수는 절대 "선택"이 아닙니다. "반드시 표기해야 하는" 필수 문법입니다.

// 상태(멤버데이타)를 변경하지 않는 모든 멤버 함수는 
// "반드시 상수 멤버 함수" 로 해야 합니다.

// 지금까지 배운 모든 클래스의 "getxxx" 함수는 반드시 "상수 멤버함수"로 
// 했어야 합니다.

// 물론, 멤버 데이타를 수정하게 되는 함수("setxxx") 는 "상수 멤버함수"로
// 하면 안됩니다.

class Rect
{
	int x, y, w, h;
public:
	Rect(int a, int b, int c, int d)
		: x(a), y(b), w(c), h(d) {}

	int getArea() const { return w * h; }
};


//void foo(Rect r) // call by value : 복사본의 오버헤드가 있습니다.
				   //					사용자 타입에대해서는 사용하지 마세요

void foo(const Rect& r)  // 이 코드가 좋은 코드입니다. 꼭 이렇게 하세요
{
	int n = r.getArea(); // ?????
}


int main()
{
	Rect r(1, 1, 10, 10); // 상수 객체 아닙니다.

	int n = r.getArea();  // ok.. 아무 문제 없습니다.

	foo(r);
}



