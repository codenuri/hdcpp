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

	BaseMenu* get_submenu(int idx) { return v[idx]; }
};

class MenuItem : public BaseMenu
{
	int id;

	using HANDLER = void(*)();  // typedef void(*HANDLER)()

	HANDLER handler = nullptr;

public:
	MenuItem(const std::string& t, int i) : BaseMenu(t), id(i) {}

	void set_handler(HANDLER h) { handler = h;}

	void command() override
	{
		// 여기서 어떤 작업을 하면
		// 모든 메뉴가 동일한 작업을 하게 됩니다.

		// 여기서는 등록된 함수를 다시 호출해야 합니다.

		if ( handler != nullptr )
			handler();
	}
};

void foo() { std::cout << "foo\n";}

int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1  = new PopupMenu("색상 변경");
	PopupMenu* pm2  = new PopupMenu("해상도 변경");

	root->add(pm1);
	root->add(pm2);

	MenuItem* mi = new MenuItem("WHITE", 10);
	mi->set_handler(&foo);

	pm1->add(mi);


	pm1->add( new MenuItem("RED",   11));
	pm1->add( new MenuItem("GREEN", 12));
	pm1->add( new MenuItem("BLUE",  13));
	pm1->add( new MenuItem("WHITE",  14));

	pm2->add( new MenuItem("HD",  21));
	pm2->add( new MenuItem("FHD", 22));
	pm2->add( new MenuItem("UHD", 23));

	root->command();
	delete root; 
}


