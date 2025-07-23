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
	virtual Shape* create_shape() = 0;
};



class AddRectCommand : public AddCommand 
{
public:
	using AddCommand::AddCommand; 

 	virtual Shape* create_shape() { return new Rect;}
};



class AddCircleCommand : public AddCommand 
{
public:
	using AddCommand::AddCommand; 

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

// 여러 명령을 저장해서 한번에 실행하는 매크로
class Macro
{
	std::vector<ICommand*> v;
public:
	void add(ICommand* cmd) { v.push_back(cmd);}

	void execute()
	{
		for( auto cmd : v)
			cmd->execute();
	}
};




int main()
{
	std::vector<Shape*> v;

	Macro* mc1 = new Macro;
	mc1->add(new AddRectCommand(v));
	mc1->add(new AddCircleCommand(v));
	mc1->add(new DrawCommand(v));
	mc1->execute();

	Macro* mc2 = new Macro;
	mc2->add(new AddRectCommand(v));
	mc2->add(new AddCircleCommand(v));
	mc2->add( ? );




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







