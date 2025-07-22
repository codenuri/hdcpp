#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

class MenuItem 
{
	std::string title;
	int id;
public:
	MenuItem(const std::string& t, int i) : title(t), id(i) {}

	std::string get_title() const { return title;}

	void command()
	{
		std::cout << get_title() << "메뉴 선택됨\n";

		getchar(); 
	}
};

class PopupMenu
{
	std::string title;
	std::vector<MenuItem*> v;
public:
	PopupMenu( const std::string& t) : title(t) {}

	void add(MenuItem* m) { v.push_back(m);}

	void command()
	{		
		auto sz = v.size();

		for( int i = 0; i < sz; i++)
		{
			std::cout << i + 1 << ". " << v[i]->get_title() << '\n';
		}
		std::cout << "메뉴 선택하세요 >> ";
		int cmd;
		std::cin >> cmd;

		// 선택된 메뉴 실행
		v[cmd-1]->command();

	}
};





int main()
{
	MenuItem m1("김밥", 11);
	MenuItem m2("라면", 51);

	PopupMenu pm("오늘의 점심");
	pm.add(&m1);
	pm.add(&m2);

	pm.command();  // 팝업메뉴 선택시 동작을 생각해 보세요
				   // 1. 김밥
				   // 2. 라면
				   // => 메뉴를 선택하세요 >> 
}




