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

template<typename T>
class AddCommand : public ICommand 
{
	std::vector<Shape*>& v;
public:
	AddCommand(std::vector<Shape*>& v) : v(v) {}

	void execute()  override { v.push_back( new T ); }
	// 단, 이방식은 객체를 생성하는 방법이 동일하다는 조건
	// new Rect(x, y, w, h)
	// new Circle(x, y, radius) <== 실제는 모양이 달라 집니다.

	bool can_undo() override { return true; } 
	void undo()     override 
	{ 
		Shape* s = v.back();
		v.pop_back();

		delete s;
	} 
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
			command = new AddCommand<Rect>(v);
			command->execute();

			undo_stack.push(command);
		}
		else if (cmd == 2) 
		{
			command = new AddCommand<Circle>(v);
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







