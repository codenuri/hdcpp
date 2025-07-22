#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 
#include "getch.h" // DAY1 에서 복사해오세요

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

		_getch(); 
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
		while( true)
		{
			system("cls"); // 화면지우기 명령. 에러나오면 지우세요 system("clear")

			// 아래 코드 이위치에
			auto sz = v.size();

			for( int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->get_title() << '\n';
			}
			std::cout << sz + 1 << ". 종료\n";

			std::cout << "메뉴 선택하세요 >> ";
			int cmd;
			std::cin >> cmd;

			if ( cmd == sz + 1) // 종료 선택
				break;

			if ( cmd < 1 || cmd > sz + 1)	// 잘못된 입력
				continue;

			// 선택된 메뉴 실행
			v[cmd-1]->command();
		}

	

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




