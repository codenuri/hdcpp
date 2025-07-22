#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 
#include "getch.h" 

// C 언어 : 포인터 등을 학습할때 메모리 구조를 파악하기 메모리 그림을 그리게 됩니다.
// 객체지향 디자인 : 클래스의 구조를 그리면 디자인을 이해하기 쉽습니다.

// PopupMenu 는 MenuItem 뿐 아니라 PopupMenu 자신도 보관 해야 한다.
// Folder    는 File     뿐 아니라 Folder 자신도 보관 해야 한다.
// 복합객체   는 개별객체 뿐 아니라 복합객체 자신도 보관 해야 한다.
// => 공통의 기반 클래스를 설계하라!!!
// => "Composite(포함)" 라는 패턴


class BaseMenu 
{
public:

};











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
	pm.add(&kimbab); 
	pm.add(&m9);

	pm.command(); 
}




