// 7_객체생성정리
class Rect
{
};

// 객체를 만드는 방법

int main()
{
	// #1. 
	Rect rc1;

	// #2.
	Rect* rc2 = new Rect;

	// #3. 
	Rect* rc3 = Rect::create();

	// #4.
	Rect* rc4 = rc3->clone();

	// #5. 
	Rect* rc5 = factory.create();

}