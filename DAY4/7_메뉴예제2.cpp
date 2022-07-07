#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

class MenuItem
{
	std::string title;
	int id;
public:
	MenuItem(const std::string& s, int n) : title(s), id(n) {}

	std::string getTitle() const { return title; }

	void command()
	{
		std::cout << getTitle() << " 메뉴 선택 됨" << std::endl;
		_getch(); 
	}
};

class PopupMenu
{
	std::string title;
	std::vector<MenuItem*> v; // 하위메뉴들을 보관
public:
	PopupMenu(const std::string& s) : title(s) {}

	void addMenu(MenuItem* p) { v.push_back(p); } 

	// 팝업메뉴 선택시 해야 할일을 생각해 보세요.
	void command()
	{

	}
};


int main()
{
	MenuItem m1("김밥", 11);
	MenuItem m2("라면", 12);


	PopupMenu pm("오늘의 식단");

	pm.addMenu(&m1);
	pm.addMenu(&m2);

	pm.command(); // 팝업 메뉴를 선택할때 해야 할일을 생각해 보세요

}
