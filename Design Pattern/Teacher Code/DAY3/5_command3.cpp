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
//--------------------------------------------------
struct ICommand
{
	virtual void execute() = 0;
	virtual bool can_undo() { return false; }
	virtual void undo() {}

	virtual ~ICommand() {}
};

// ���α׷����� ����ϴ� ��� ���(�۾�)�� Ŭ������ �����մϴ�.
class AddRectCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	AddRectCommand(std::vector<Shape*>& v) : v(v) {}

	void execute() override { v.push_back(new Rect);}

	bool can_undo() override { return true; }

	void undo() override
	{
		Shape* s = v.back(); // ��ȯ��
		v.pop_back();		 // ����
		delete s;
	}
};

class AddCircleCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	AddCircleCommand(std::vector<Shape*>& v) : v(v) {}

	void execute() override { v.push_back(new Circle); }

	bool can_undo() override { return true; }

	void undo() override
	{
		Shape* s = v.back(); // ��ȯ��
		v.pop_back();		 // ����
		delete s;
	}
};

class DrawCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	DrawCommand(std::vector<Shape*>& v) : v(v) {}

	void execute() override 
	{ 
		for (auto e : v)
			e->draw();
	}

	bool can_undo() override { return true; }

	void undo() override
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

			undo_stack.push(command); // undo �� ���ؼ� ����
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

		else if (cmd == 0)
		{
			if (!undo_stack.empty())
			{
				command = undo_stack.top(); // ��ȯ���ǰ�
				undo_stack.pop();			// ���� ���Ŵ� ���⼭

				if (command->can_undo())
				{
					command->undo();
				}

				delete command; // redo �� �����Ϸ��� ������ ����
								// redo_stack.push(command)
			}
		}
	}
}

// C++ �� ���� GUI ���̺귯���� QT �� ���� "UndoManager" �� �ֽ��ϴ�.
// C# WPF ���̺귯���� �޴� �̺�Ʈ ó���� ���� "class" �� ����� ���� �����մϴ�.
// => ��� "Command" ���� �Դϴ�.



// �Լ� : ���� �Ѱ��� ���� �մϴ�.(execute, ��, �ؾ� ����)
//		  ����Ÿ ���� �ȵ�
// 
// class : ���� ������ ���� ����(��� �Լ� ������, execute, undo ��)
//		   ����Ÿ ���� ����(�������Ÿ)
//		   undo �� ���� ����Ÿ ���� ����

