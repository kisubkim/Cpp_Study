#include <iostream>
#include <list>
#include <vector>

// concrete visitor
template<typename T>
class TwiceVisitor
{
public:
	void visit(T& e) { e *= 2; }
};

template<typename T>
class ShowVisitor
{
public:
	void visit(T& e) { std::cout << e << std::endl; }
};

template<typename T>
class ResetVisitor
{
public:
	void visit(T& e) { e = 0; }
};




template<typename T> class MyList : public std::list<T>
{
public:
	using std::list<T>::list;

	// �������̽�������� �پ��� �湮�ڸ� ���� ����
	// template �������!
	template<typename V>
	void accept(V* visitor)
	{
		for (auto& e : *this)
			visitor->visit(e);

	}
};

int main()
{
	MyList<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	TwiceVisitor<int> tv;
	s.accept(&tv);

	ShowVisitor<int> sv; // ��Ҹ� ����ϴ� �湮�� ����� ������
	s.accept(&sv);

	ResetVisitor<int> zv; // ��Ҹ� 0 ���� ����� �湮��
	s.accept(&zv);

	s.accept(&sv);
}




