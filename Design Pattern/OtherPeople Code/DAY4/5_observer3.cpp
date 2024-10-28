#include <iostream>
#include <vector>

class Subject;	// 클래스 전방 선언(forward declaration)
// 완전한 선언이 없어도 포인터 변수는 선언 가능.
// 완전한 선언이 없어도 포인터는 크기를 알수 있다.(항상 같은크기)

struct IGraph
{
	virtual void update(int data) = 0;
	virtual ~IGraph() {}

	// 관찰자는 자신이 누구를 관찰하는지 알아야 한다.
	// => 그래야 변경된 데이타를 얻을수 있다.
	Subject* subject = nullptr;
};


class Subject
{
	std::vector<IGraph*> v;
public:
	void attach(IGraph* p)
	{
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
	int value;

	int some_data[4] = { 1,2,3,4 };
public:

	int* get_data() { return some_data; }

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
	void update(int hint) override
	{
		// Table이 변경되었다고 통보가 왔으므로!!
		// 1. hint 만 가지고 update 할수 있다면 즉시 update 하고
		// 2. 추가 data 가 필요하면 Table 에 접근해서 data 얻는다.

//		int* data = subject->get_data(); // error.
										// subject 는 "Subject*" 타입

		Table* table = static_cast<Table*>(subject);

		int* data = table->get_data();

		// 이제 data 를 사용해서 UI 를 update..!!



		std::cout << "Bar Graph : ";

		for (int i = 0; i < hint; i++)
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

	atomic ==> HW 동기화.

	t.edit();
}
