#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 
#include "getch.h" 

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
			system("cls"); 
			auto sz = v.size();

			for( int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->get_title() << '\n';
			}
			std::cout << sz + 1 << ". 종료\n";

			std::cout << "메뉴 선택하세요 >> ";
			int cmd;
			std::cin >> cmd;

			if ( cmd == sz + 1) 
				break;

			if ( cmd < 1 || cmd > sz + 1)	
				continue;

			v[cmd-1]->command();
		}

	

	}
};





int main()
{
	MenuItem m1("참치김밥",   11);
	MenuItem m2("소고기김밥", 12);
	MenuItem m3("김치김밥",   13);
	MenuItem m9("라면",       51);

	PopupMenu kimbab("김밥류");
	kimbab.add(&m1);
	kimbab.add(&m2);
	kimbab.add(&m3);


	PopupMenu pm("오늘의 점심");
	pm.add(&kimbab); // <=== 핵심. 현재 코드는 에러
					 //            어떻게 해야 할까요 ? 다음소스에서 해결
	pm.add(&m6);

	pm.command(); 
}




