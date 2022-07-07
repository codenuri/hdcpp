#include <iostream>
#include <string>
#include <vector>
#include <conio.h> // _getch() 함수를 위한 헤더

// 객체지향 : 모든 것은 객체(타입)이다.!!

// "메뉴항목" 을 나타내는 타입
class MenuItem
{
	std::string title;
	int id;
public:
	MenuItem(const std::string& s, int n) : title(s), id(n) {}

	std::string getTitle() const { return title; }

	// 메뉴 선택시 호출되는 함수
	void command()
	{
		std::cout << getTitle() << " 메뉴 선택 됨" << std::endl;

		_getch(); // 아무키나 누를때 까지 잠시 대기
	}
};

int main()
{
	MenuItem m1("김밥", 11);
	MenuItem m2("라면", 12);

	m1.command(); // 김밥 메뉴 선택
}
