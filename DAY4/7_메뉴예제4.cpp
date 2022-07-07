#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 


class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& s) : title(s) {}

	virtual ~BaseMenu() {}

	std::string getTitle() const { return title; }

	virtual void command() = 0;
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

		}
	}
};


int main()
{
	PopupMenu* root = new PopupMenu("root");
	PopupMenu* pm1 = new PopupMenu("해상도 변경");
	PopupMenu* pm2 = new PopupMenu("색상 변경");

	root->addMenu(pm1);
//	root->addMenu(pm2);
	pm1->addMenu(pm2);

	pm1->addMenu(new MenuItem("HD",  11));
	pm1->addMenu(new MenuItem("FHD", 12));
	pm1->addMenu(new MenuItem("UHD", 13));
	pm1->addMenu(new MenuItem("8K",  14));

	pm2->addMenu(new MenuItem("RED",   21));
	pm2->addMenu(new MenuItem("GREEN", 22));
	pm2->addMenu(new MenuItem("BLUE",  23));

	// 위 메뉴의 구조를 잘 생각해 보세요
	// 이제 시작하려면 어떻게 해야 하나요 ?
	root->command();
}
// 객체지향 프로그래밍에서 "프로그램이란 ?"

// 1. 객체를 생성하고
// 2. 객체간의 관계를 설정하고 ( pm1->addMenu(메뉴아이템객체))
// 3. 객체간의 메세지를 주고 받는 것(서로의 멤버 함수를 호출한다는 의미)
// 이다!!

// 모든 것은 객체로 구성된다.