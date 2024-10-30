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

// 도형을 추가하는 명령은 유사한 점이 많음.
// "기반 클래스"
class AddCommand : public ICommand {
	std::vector<Shape*>& v;
public:
	AddCommand(std::vector<Shape*>& v) : v(v) {}

	void execute() override { v.push_back(create_shape()); }
	bool can_undo() override { return true; }
	void undo() {
		Shape* s = v.back();		// 반환
		v.pop_back();				// 제거
		delete s;
	}

	/*
		아래 code는 template method의 전형적인 형태임.
		그런데, 가상함수가 하는 일(파생 클래스가 결정하는 것)이 "객체의 종류(타입)" 만 결정.

		Factory method
			=> 객체를 생성하기  위한 Itnerface를 제공하고 사용하지만 객체의 종류는 파생클래스가 결정.
			   Template method 와 동일한 형태. (차이는 Template method는 algorithm을 변경, Factory method는 객체의 종류를 변경.
	*/
	virtual Shape* create_shape() = 0;
};

class AddRectCommand : public AddCommand {
public:
	AddRectCommand(std::vector<Shape*>& v) : AddCommand(v) {}
	Shape* create_shape() override { return new Rect; }
};

class AddCircleCommand : public AddCommand {
public:
	//AddCircleCommand(std::vector<Shape*>& v) : AddCommand(v) {}

	// 생성자 상속 문법
	//		위 생성자는 자신이 받은 인자를 기반 클래스에 보내는 일만함.
	//			=> 이럴 때는 생성자 상속 문법을 사용하면 된다.
	//		=> 아래 한 줄이 위의 생성자(주석)와 동일.
	using AddCommand::AddCommand;		// 클래스이름::생성자이름. ---> 해당 클래스의 생성자를 나도 쓰게 해줘!! 라는 의미임.

	Shape* create_shape() override { return new Circle; }
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





