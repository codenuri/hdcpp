#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 


// 모든 메뉴의 공통의 기반 클래스
class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& s)	: title(s) {}

	virtual ~BaseMenu() {}

	std::string getTitle() const { return title; }

	// 모든 메뉴는 선택될수 있다.
	// => 모든 파생클래스의 공통의 특징은 "기반 클래스에도 있어야 한다."
	// => 구현부를 제공해 줄수 없다. 파생 클래스(팝업메뉴, 메뉴아이템)에서 
	//    반드시 만들라고 지시..
	virtual void command()  = 0; 
};



class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& s, int n) : BaseMenu(s), id(n) {}

	void command()
	{
		std::cout << getTitle() << " 메뉴 선택 됨" << std::endl;
		_getch();
	}
};

class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:
	PopupMenu(const std::string& s) : BaseMenu(s) {}

	void addMenu(BaseMenu* p) { v.push_back(p); }

	
	void command()
	{
		while (1)
		{
			system("cls");  

			int sz = v.size(); 

			for (int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->getTitle() << std::endl;
			}

			std::cout << sz + 1 << ". 종료" << std::endl;

			std::cout << "메뉴 선택하세요 >> ";

			int cmd;
			std::cin >> cmd;


			if (cmd == sz + 1) 
				break;

			if (cmd < 1 || cmd > sz + 1) 
				continue; 


			v[cmd - 1]->command(); 
			// BaseMenu* 안에 command가 있어야 한다.

		}
	}
};


int main()
{
	MenuItem m1("참치 김밥",   11);
	MenuItem m2("소고기 김밥", 12);
	MenuItem m3("돈까스 김밥", 13);

	PopupMenu kimbam("김밥류");
	kimbam.addMenu(&m1);
	kimbam.addMenu(&m2);
	kimbam.addMenu(&m3);

	MenuItem m4("라면", 21);
	MenuItem m5("우동", 31);

	PopupMenu pm("오늘의 식단");

	pm.addMenu(&kimbam); // ?? 핵심 !!!
	pm.addMenu(&m4); 
	pm.addMenu(&m5);

	pm.command(); 

}
