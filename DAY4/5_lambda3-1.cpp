#include <iostream>

int main()
{
	// 에러를 모두 찾으세요
	// 람다표현식은 "임시객체". rvalue 입니다.
	auto        f1 = [](int a, int b) { return a + b; }; // ok
	auto&       f2 = [](int a, int b) { return a + b; }; // error
	const auto& f3 = [](int a, int b) { return a + b; }; // ok
	auto&&      f4 = [](int a, int b) { return a + b; }; // ok

	// 위 코드중 제일 좋은 것은 ?

	Point pt1 = Point{};
				// 문법적으로 정확히는 "임시객체" 생성후 pt1복사지만
				// 거의 모든 C++ 컴파일러는 아래 한줄로 변경
				// Point pt1   <== 오버 헤드 없음

	const Point& pt2 = Point{};
				// 참조는 결국 포인터!
				// Point* pt2 = 임시객체의 주소(직접 구할수 없지만, 컴파일시)
				// pt2.set() => pt2->set()
				// 즉, 포인터를 따라가서 실행 느림.. 
}

