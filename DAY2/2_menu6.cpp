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
};





int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1  = new PopupMenu("색상 변경");
	PopupMenu* pm2  = new PopupMenu("해상도 변경");

	root->add(pm1);
//	root->add(pm2);
	pm1->add(pm2);

	pm1->add( new MenuItem("RED",   11));
	pm1->add( new MenuItem("GREEN", 12));
	pm1->add( new MenuItem("BLUE",  13));
	pm1->add( new MenuItem("WHITE",  14));

	pm2->add( new MenuItem("HD",  21));
	pm2->add( new MenuItem("FHD", 22));
	pm2->add( new MenuItem("UHD", 23));

	// Composite 패턴 특징 : 객체(메뉴) 의 포함관계가 Tree 모양으로 됩니다.

	// 이제 시작하려면 ?
	root->command();

	// 메모리 안전하게 삭제하려면
	// #1. 스마트 포인터 사용 => std::shared_ptr   (복습할때 적용해 보세요)
	// #2. root 메뉴만 삭제하면 자동 삭제되도록 디자인
	delete root; // 이순간 PopupMenu 소멸자 호출
				 // 소멸자에서 자신이 가진 모든 하위 메뉴 삭제
}


// 객체지향 프로그램에서 "프로그램" 이란?

// 1. 객체 생성하고
// 2. 객체 간의 관계를 설정하고
// 3. 객체 간의 메세지를 주고 받는 과정이다.(서로의 멤버 함수 호출)

// 4. 프로그램의 기본 단위는 "함수" 가 아닌 "클래스" 이다.

// 장점 : 유지보수가 편리하고, 확장성이 있다.

// 단점 : C보다 느리고(가상함수, 함수호출증가), 
// 		  메모리 사용량 증가(가상함수테이블, 필요없는 멤버데이타등)
//        어렵다!!(C보다 아주 배우기 어렵다)


