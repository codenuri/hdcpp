#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 
#include "getch.h" 

class BaseMenu 
{
	std::string title;
public:
	BaseMenu(const std::string& t) : title(t) {}

	virtual ~BaseMenu() {} 

	std::string get_title() const { return title;}

	virtual void command() = 0;
};


class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& t, int i) : BaseMenu(t), id(i) {}

	void command() override
	{
		std::cout << get_title() << "메뉴 선택됨\n";

		_getch(); 
	}
};

class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:
	PopupMenu( const std::string& t) : BaseMenu(t) {}

	void add(BaseMenu* m) { v.push_back(m);}

	~PopupMenu()
	{
		for( auto m : v)
			delete m;
	}




	void command() override
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

	// 자신의 하위 메뉴 포인터를 반환하는 함수
	BaseMenu* get_submenu(int idx) { return v[idx]; }
};


int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1  = new PopupMenu("색상 변경");

	pm1->add( new MenuItem("RED",   11));
	pm1->add( new MenuItem("GREEN", 12));

	root->add(pm1);
	root->add( new MenuItem("HD",  21));

	// 아래 멤버 함수를 만들어 봅시다.
	auto m = root->get_submenu(0);






	root->command();

	delete root; 
}


