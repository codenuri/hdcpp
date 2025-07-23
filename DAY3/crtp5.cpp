#include <iostream>

// 주의 사항

class Window 
{
	int handle;
	int color;
public:
	void move() {}
	void show() {}

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



int main()
{
	MainWindow w;		
	
	// 이 기술을 click() 이 event_loop 에서만 호출되는 경우에 사용해야 합니다.
	// 외부에서 아래처럼 호출되는 경우는 사용하면 안됩니다.
	// => 현재 시나리오에서는 click()을 직접 호출할 이유는 없습니다
	// => 안전하게 protected 권장
	Window* p = &w;
	p->click();

	w.event_loop();
}