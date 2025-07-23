#include <iostream>
#include <string>
#include <vector>
#include <stack>

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw rect" << std::endl; }
};

class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw circle" << std::endl; }
};

//-----------------------
struct ICommand
{
	virtual void execute() = 0;
	virtual bool can_undo() { return false;}; 
	virtual void undo() {} 
	virtual ~ICommand() {}
};

// 도형을 추가하는 명령은 유사한 코드가 많습니다.
// 기반 클래스를 만들어서 동일한 코드를 제공합니다.
class AddCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	AddCommand(std::vector<Shape*>& v) : v(v) {}

	void execute()  override { v.push_back( create_shape() ); }
	bool can_undo() override { return true; } 
	void undo()     override 
	{ 
		Shape* s = v.back();
		v.pop_back();

		delete s;
	}

	// 객체를 만들기 위한 인터페이스(순수가상함수)를 제공하고
	// 사용도 하고 있지만(execute에서 호출)
	// 실제 어떤 타입의 객체를 만들지는 파생 클래스가 결정한다.
	// => "factory method" 라는 패턴
	// => "template method" 와 동일한 구조지만
	//    가상함수가 하는 일이 알고리즘(정책)의 결정이 아닌 객체타입 결정
	virtual Shape* create_shape() = 0;
};



class AddRectCommand : public AddCommand 
{
public:
	AddRectCommand(std::vector<Shape*>& v) : AddCommand(v) {}

 	virtual Shape* create_shape() { return new Rect;}
};

class AddCircleCommand : public AddCommand 
{
public:
	AddCircleCommand(std::vector<Shape*>& v) : AddCommand(v) {}

 	virtual Shape* create_shape() { return new Circle;}
};


class DrawCommand : public ICommand 
{
	std::vector<Shape*>& v;
public:
	DrawCommand(std::vector<Shape*>& v) : v(v) {}

	void execute()  override 
	{ 
		for( auto s : v ) s->draw();
	}
	bool can_undo() override { return true; } 
	void undo()     override 
	{ 
		system("cls"); 
	} 
};





int main()
{
	std::vector<Shape*> v;

	std::stack<ICommand*> undo_stack;
	std::stack<ICommand*> redo_stack;

	ICommand* command = nullptr;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1) 
		{
			command = new AddRectCommand(v);
			command->execute();

			undo_stack.push(command);
		}
		else if (cmd == 2) 
		{
			command = new AddCircleCommand(v);
			command->execute();

			undo_stack.push(command);
		}
		else if (cmd == 9)
		{
			command = new DrawCommand(v);
			command->execute();

			undo_stack.push(command);
		}
		else if ( cmd == 0 )
		{
			if ( undo_stack.empty() == false )
			{
				command = undo_stack.top();
				undo_stack.pop();

				if ( command->can_undo() )
				{
					command->undo();
				}
				delete command; 
			}
		}
	}
}







