#include <iostream>

// template hoisting 이라는 이름의 C++ IDioms
// 클래스 템플릿 만들때 "T" 를 사용하지 않은 멤버가 있다면
// 템플릿이 아닌 기반 클래스를 만들어서 제공해라

class Window 
{
	int handle;
	int color;
public:
	void move() {}
	void show() {}

	// click() 등의 이벤트 처리함수 수백개...
	void click() { std::cout << "Window click\n"; }
};


template<typename T>
class EventWindow : public Window
{
public:
	void event_loop()
	{
		static_cast<T*>(this)->click();
	}
};

class MainWindow : public EventWindow<MainWindow>
{
public:
	void click() { std::cout << "MainWindow click\n"; }
};

class ImageView : public EventWindow<ImageView>
{
public:
	void click() { std::cout << "MainWindow click\n"; }
};

int main()
{
	MainWindow w;		
	
	w.event_loop();
}