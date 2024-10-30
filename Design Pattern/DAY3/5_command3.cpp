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
	program에서 사용하느 모든 명령(작업)을 클래스로 설계
*/

class AddRectCommand : public ICommand {
	std::vector<Shape*>& v;
public:
	AddRectCommand(std::vector<Shape*>& v) : v(v) {}

	void execute() override { v.push_back(new Rect); }
	bool can_undo() override { return true; }
	void undo() {
		Shape* s = v.back();		// 반환
		v.pop_back();				// 제거
		delete s;
	}
};

class AddCircleCommand : public ICommand {
	std::vector<Shape*>& v;
public:
	AddCircleCommand(std::vector<Shape*>& v) : v(v) {}

	void execute() override { v.push_back(new Circle); }
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
			command = new AddRectCommand(v);
			command->execute();

			undo_stack.push(command);		// undo 를 위해 보관
		}
		else if (cmd == 2) {
			command = new AddCircleCommand(v);
			command->execute();

			undo_stack.push(command);		// undo 를 위해 보관
		}
		else if (cmd == 9)
		{
			command = new DrawCommand(v);
			command->execute();

			undo_stack.push(command);		// undo 를 위해 보관
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


/*
	C++로 만든 GUI library 인 QT에 보면 "UndoManager" 가 있음.
	C# WPF Library는 Menu Event 처리를 위해 "class"로 만드는 것을 권장.

	==> 위 2개 모두 Command Pattern 임.

	Function : 동작 한개만 정의. (execute, 즉, 해야할 일)
	Class : 동작 여러개 정의 가능 (Member Function 여러개, execute, undo, etc.)
			Data 보관 가능(Member Data)
			Undo 를 위한 데이터 보관 가능

*/







