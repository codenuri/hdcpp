#include <iostream>

class Window
{
public:
	void event_loop()
	{
		// UI 에서 발생된 event 는 시스템 의 event(message) Q 에 놓이게 됩니다.
		// Q 에서 event 를 꺼내서 약속된 함수를 호출합니다.
		// event 는 100개 이상이 존재하고 모두 약속된 함수가 있습니다.
		click();
	}
	void click() { std::cout << "Window click\n"; }
};

// 위 클래스를 라이브러리 내부
// 개발자는 파생클래스 만들어서 이벤트 처리
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