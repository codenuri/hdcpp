// 3_변수6.cpp   25 page 

struct Point
{
	int x, y;
};
int main()
{
	Point pt = { 1,2 };

	// 구조체형 변수에서 값을 꺼내는 일반 적인 방법
	int x = pt.x;
	int y = pt.y;

	// C++17 부터는 한줄로 모든 멤버 값을 꺼낼수 있습니다.
	// "structural binding" 이라는 문법
	auto [a1, a2] = pt; // auto a1 = pt.x
						// auto a2 = pt.y
}
