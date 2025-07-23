#include <iostream>

class Window
{
public:
	void event_loop()
	{
		// 멤버 함수 호출은 반드시 객체가 있어야 합니다.
		// 아래 코드가 객체가 없는것 같지만 
		// 왼쪽 주석 처럼 됩니다.
		// 이때. 현재 this의 타입은 Window* 입니다.
		click();	// this->click()

		// 따라서 click 이 가상이 아니면
		// this 의 타입으로 호출 결정 : Window click 호출
		
		// 가상이면 this가 가리키는 곳의 객체 조사후 호출
		// => 지금은 MainWindow 객체이므로 MainWindow click 호출
	}
	virtual void click() { std::cout << "Window click\n"; }
};


class MainWindow : public Window 
{
public:
	void click() { std::cout << "MainWindow click\n"; }
};

int main()
{
	MainWindow w;		
	
	w.event_loop();
}