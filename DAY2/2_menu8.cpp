#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 
#include "getch.h" 

class unsupported_operation {};

class BaseMenu 
{
	std::string title;
public:
	BaseMenu(const std::string& t) : title(t) {}

	virtual ~BaseMenu() {} 

	std::string get_title() const { return title;}

	virtual void command() = 0;

	// add 는 PopupMenu 에만 필요하지만
	// 캐스팅 없이 사용하기 위해 BaseMenu 에서도 제공
	virtual void add(BaseMenu*) { throw unsupported_operation();}
	virtual BaseMenu* get_submenu(int idx) { throw unsupported_operation();}
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

	// 해결책 #2. 캐스팅 없이 아래 처럼 사용할수 있게 해 봅시다.
	// => 한가지 방법밖에 없다.
	// => BaseMenu 에서 add 선언 제공해야 한다.
	root->get_submenu(0)->add( new MenuItem("BLACK", 13));






	root->command();

	delete root; 
}


