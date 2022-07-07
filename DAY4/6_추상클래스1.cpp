// 3_추상클래스 - 168 page

// 추상 클래스(abstract class) : 순수 가상함수가 한개 이상 있는 클래스
// 특징 : 객체를 생성할수 없습니다.
// 의도 : 파생 클래스 만들때 특정한 함수(Draw)를 반드시 만들라고 지시하는것
class Shape
{
public:
	virtual void Draw()  = 0; // 순수 가상 함수 
							  // pure virtual function
							  // 구현부가 없고, 끝부분에 "=0" 으로 표기
};

class Rect : public Shape
{
public:
	// Draw 의 구현부를 제공하지 않으면 역시 추상 클래스 입니다.
	void Draw() override {}  // 이 코드가 있으면 추상 클래스가 아닙니다.
};
int main()
{
	Shape s; // error. 추상 클래스는 객체 생성이 안됩니다.
	Rect  r; // error. Draw()의 구현부를 만들지 않으면
}


