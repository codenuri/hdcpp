// override.cpp  147 page ~

class Shape
{
public:
	virtual void draw() {};
};
class Rect : public Shape
{
public:
	// 1. 가상 함수 override 시에 "virtual" 을 적어도 되고 빼도 됩니다.
	virtual void draw()  {};
};

class Circle : public Shape
{
public:
	// 2. 가상함수 override 시에 "오타" 발생- "draw" 인데 "Draw"로 
	// => 에러가 아니라, 컴파일러는 새로운 가상함수를 추가했다고 생각합니다.
	// => 이 현상 때문에 C++ 코드에서 버그가 많았었습니다.
//	virtual void Draw() {};

	// 3. C++11 부터 위와 같은 오류를 줄이기 위해 새로운 키워드 등장
	// => 가상함수 재정의시 "override" 를 붙이면 좋다.
	// => override : 새로운 함수를 만드는 것이 아니라, 기반 클래스 함수를 
	//               override 한다고 알려주는 것
	virtual void Draw() override {} // error. 기반 클래스에 "Draw"는 없다
};


int main()
{

}
