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

class AddRectCommand : public ICommand 
{
	std::vector<Shape*>& v;
public:
	AddRectCommand(std::vector<Shape*>& v) : v(v) {}

	void execute()  override { v.push_back( new Rect ); }
	bool can_undo() override { return true; } 
	void undo()     override 
	{ 
		Shape* s = v.back();
		v.pop_back();

		delete s;
	} 
};


class AddCircleCommand : public ICommand 
{
	std::vector<Shape*>& v;
public:
	AddCircleCommand(std::vector<Shape*>& v) : v(v) {}

	void execute()  override { v.push_back( new Circle ); }
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
		system("cls"); // 또는 system("clear")
					   // std::cout << "지우기\n"
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
			if ( undo_stack.empty() != false )
			{
				command = undo_stack.top();
				undo_stack.pop();

				if ( command->can_undo() )
				{
					command->undo();
				}
				delete command; // redo 지원하려면 delete 하지말고
								// redo_stack.push_back(command) 하세요
			}
		}
	}
}







