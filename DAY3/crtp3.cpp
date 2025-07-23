#include <iostream>

// 가상함수사용시
// => 가상함수 테이블이 생성됩니다.
// => 모든 가상함수의 주소가 메모리 어딘가 보관됩니다.
// => 1000개 가상함수 * 32 비트 환경 => 대략 4K 메모리 오버헤드

class Window
{
public:
	void event_loop()
	{
//		click();	 // this->click() 에서 this가 Window* 이므로

		static_cast<MainWindow*>(this)->click();

	}
	void click() { std::cout << "Window click\n"; }
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