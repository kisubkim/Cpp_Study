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

//---------------------------------------------------------
struct ICommand {
	virtual void execute() = 0;
	virtual bool can_undo() { return false; }
	virtual void undo() {}

	virtual ~ICommand() {}
};

/*
	C++ 에서는 Factory Method 보다는 Template을 더 선호.
*/

template<typename T>
class AddCommand : public ICommand {
	std::vector<Shape*>& v;
public:
	AddCommand(std::vector<Shape*>& v) : v(v) {}

	void execute() override { v.push_back(new T); }
	bool can_undo() override { return true; }
	void undo() {
		Shape* s = v.back();		// 반환
		v.pop_back();				// 제거
		delete s;
	}
};

class DrawCommand : public ICommand {
	std::vector<Shape*>& v;
public:
	DrawCommand(std::vector<Shape*>& v) : v(v) {}

	void execute() override {
		for (auto e : v)
			e->draw();
	}

	bool can_undo() override { return true; }
	void undo() {
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

		if (cmd == 1) {
			command = new AddCommand<Rect>(v);
			command->execute();

			undo_stack.push(command);
		}
		else if (cmd == 2) {
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
		else if (cmd == 0) {
			if (!undo_stack.empty()) {
				command = undo_stack.top();
				undo_stack.pop();
				if (command->can_undo())
					command->undo();
				delete command;
			}
		}
	}
}





