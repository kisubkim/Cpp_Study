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

struct ICommand
{
	virtual void execute() = 0;
	virtual void undo() = 0;
	virtual bool can_undo() { return false; }
	virtual bool can_execute() { return true; }
	virtual ~ICommand() {}
};

class AddRectCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	AddRectCommand(std::vector<Shape*>& v) :v(v) {}
	void execute() override { v.push_back(new Rect); }
	bool can_undo() override { return true; }
	bool can_execute() override { return !v.empty(); }
	void undo() override
	{
		if (!can_execute())
			return;
		Shape* s = v.back();
		v.pop_back();
		delete s;
	}
};

class AddCircleCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	AddCircleCommand(std::vector<Shape*>& v) :v(v) {}
	void execute() override { v.push_back(new Circle); }
	bool can_undo() override { return true; }
	bool can_execute() override { return !v.empty(); }
	void undo() override
	{
		if (!can_execute())
			return;
		Shape* s = v.back();
		v.pop_back();
		delete s;
	}
};

class DrawCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	DrawCommand(std::vector<Shape*>& v) :v(v) {}
	void execute() override { for (auto s : v) s->draw(); }
	bool can_undo() override { return true; }
	bool can_execute() override { return !v.empty(); }
	void undo() override
	{
		system("cls");
	}
};


int main()
{
	std::vector<Shape*> v;
	std::stack <ICommand*> cmd_stack;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 0) {
			if (cmd_stack.empty() == true) continue;
			ICommand* command = cmd_stack.top();
			cmd_stack.pop();
			if(command->can_undo())
				command->undo();
			delete command;
		}
		else if (cmd == 1) {
			ICommand* command = new AddRectCommand(v);
			command->execute();
			cmd_stack.push(command);
		}
		else if (cmd == 2) {
			ICommand* command = new AddCircleCommand(v);
			command->execute();
			cmd_stack.push(command);
		}
		else if (cmd == 9)
		{
			ICommand* command = new DrawCommand(v);
			command->execute();
			cmd_stack.push(command);
		}
	}
}







