//1_관찰자패턴1 - 94 page
#include <iostream>
#include <vector>


class Subject;		// class 전방선언.
					// 완전한 선언이 없어도 포인터 변수는 사용가능함.

struct IGraph
{
	virtual void update(int data) = 0;
	virtual ~IGraph() {}

	// 모든 관찰자(그래프)는 관차의 대상(Table)을 알게 하기 위해서ㅣ.
	Subject* subject = nullptr;

};

// Table의 데이타 형태와 상관없이 관찰자 패턴의 기본로직은 동일함.
// 관찰자 패턴의 기본로직을 기반 클래스로 제공.

// 관찰의 대상을 "Subject" 라고 함.
class Subject {
	std::vector<IGraph*> v;
public:
	virtual ~Subject() {}
	void attach(IGraph* p) {
		v.push_back(p);
		p->subject = this;
	}
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

	int data[5] = { 1, 2, 3, 4, 5 };
public:
	int* get_data() { return data; }

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
		// Table이 변경되었다고 통보가 왔으므로 다시 Table에 접근해서 Data를 가져 ㅇ온다.

		//int* data = subject->get_data();		// error
												// subject는 Tablee을 가리키지만 "subject*" 이므로 Error


		Table* table = static_cast<Table*>(subject);
		int* data = table->get_data();

		/*
			이제 data 배열을 사용해서 그래프를 update 하면 됨.

			관찰자 패턴은 library들이 아주 많이 사용.
			그런데 이름을 자신들만의 이름으로 변경해서 사용

			C++ MFC : Document(Table)	/	View (Graph)
			QT		: Model(Table)		/	View (Graph)
		*/

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





