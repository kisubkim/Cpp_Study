//1_관찰자패턴1 - 94 page
#include <iostream>
#include <vector>


struct IGraph
{
	virtual void update(int data) = 0;
	virtual ~IGraph() {}
};

// Table의 데이타 형태와 상관없이 관찰자 패턴의 기본로직은 동일함.
// 관찰자 패턴의 기본로직을 기반 클래스로 제공.

// 관찰의 대상을 "Subject" 라고 함.
class Subject {
	std::vector<IGraph*> v;
public:
	virtual ~Subject() {}
	void attach(IGraph* p) { v.push_back(p); }
	void detach(IGraph* p) { }

	void notify(int data)
	{
		for (auto p : v)
			p->update(data);
	}
};

class Table : public Subject
{
	int value; // table 의 data 값
public:
	
	
	void edit()
	{
		while (1)
		{
			std::cout << "Data >>";
			std::cin >> value;
			notify(value);
		}
	}
};
//----------------------
class BarGraph : public IGraph
{
public:
	void update(int n) override
	{
		std::cout << "Bar Graph : ";

		for (int i = 0; i < n; i++)
			std::cout << "*";

		std::cout << std::endl;
	}
};

class PieGraph : public IGraph
{
public:
	void update(int n) override
	{
		std::cout << "Pie Graph : ";

		for (int i = 0; i < n; i++)
			std::cout << ")";

		std::cout << std::endl;
	}
};

int main()
{
	Table t;
	PieGraph pg; t.attach(&pg);
	BarGraph bg; t.attach(&bg);
	t.edit();
}





