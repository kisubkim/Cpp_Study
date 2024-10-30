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


/*
	여러개의 명령을 보관했다가 한번에 실행하는 매크로 명령
*/

class Macro : public ICommand {		// composite pattern 적용.
	std::vector<ICommand*> v;
public:
	void add(ICommand* c) { v.push_back(c); }

	void execute() {
		for (auto e : v) {
			e->execute();
		}
	}
};

int main()
{
	std::vector<Shape*> v;

	std::stack<ICommand*> undo_stack;
	std::stack<ICommand*> redo_stack;

	ICommand* command = nullptr;

	Macro* m1 = new Macro;
	m1->add(new AddCommand<Rect>(v));
	m1->add(new AddCommand<Circle>(v));
	m1->add(new DrawCommand(v));
	m1->execute();

	Macro* m2 = new Macro;
	m2->add(new AddCommand<Rect>(v));
	m2->add(new AddCommand<Circle>(v));
	m2->add(m1);
	m2->execute();

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





