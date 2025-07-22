#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 
#include <functional> // std::bind, std::function - C++11 부터 지원
#include "getch.h" 
using namespace std::placeholders; // _1, _2, _3.... 


class unsupported_operation {};

class BaseMenu 
{
	std::string title;
public:
	BaseMenu(const std::string& t) : title(t) {}

	virtual ~BaseMenu() {} 

	std::string get_title() const { return title;}

	virtual void command() = 0;

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

	using HANDLER = std::function<void()>;

	std::vector<HANDLER> v; // 메뉴 선택시 여러함수에 전달 가능하게
							// observer 패턴 : 발생된 이벤트를 여러곳에 전달
public:
	MenuItem(const std::string& t, int i, HANDLER h = nullptr) 
		: BaseMenu(t), id(i) 
	{
		if ( h != nullptr )
			v.push_back(h);
	}

	void add_handler(HANDLER h) { v.push_back(h);}



	void command() override
	{
		// 등록된 모든 함수에게 메뉴가 선택되었음을 통보
		for( auto f : v)
			f();
	}
};

// 테스트용 코드
// function3.cpp 안에 foo, goo, Car 복사해오세요
void foo()       { std::cout << "foo\n"; _getch(); }
void goo(int id) { std::cout << "goo : " << id << '\n'; _getch(); }

class Car
{
public:
	void start_record(int resolution) 
	{
		std::cout << "녹화시작. 해상도 : " << resolution << '\n';
		_getch();
	}
	void end_record()
	{
		std::cout << "녹화종료 \n";
		_getch();
	}
};
//---------------------------------------------
int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1  = new PopupMenu("색상 변경");
	PopupMenu* pm2  = new PopupMenu("해상도 변경");

	root->add(pm1);
	root->add(pm2);

	pm1->add( new MenuItem("RED",   11));
	pm1->add( new MenuItem("GREEN", 12));
	pm1->add( new MenuItem("BLUE",  13));
	pm1->add( new MenuItem("WHITE",  14));

	MenuItem* mi = new MenuItem("HD",  21, &foo);

	pm2->add( mi );
	pm2->add( new MenuItem("FHD", 22, std::bind(&goo, 22)));
	pm2->add( new MenuItem("UHD", 23, std::bind(&goo, 23)));

	Car car;
	mi->add_handler(std::bind(&Car::start_record, &car, 1024));
	mi->add_handler(std::bind(&Car::end_record, &car));
	mi->add_handler([](){std::cout << "lambda\n";_getch();});

	root->command();
	delete root; 
}


