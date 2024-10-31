#include <iostream>
#include <list>
#include <vector>





// �湮�� �������̽�
template<typename T>
struct IVisitor
{
	virtual void visit(T& e) = 0;

	virtual ~IVisitor() {}
};

template<typename T>
class TwiceVisitor : public IVisitor<T>
{
public:
	void visit(T& e) { e *= 2; }
};

// ShowVisitor, ZeroVisitor ���弼��

template<typename T>
class ShowVisitor : public IVisitor<T>
{
public:
	void visit(T& e) { std::cout << e << std::endl; }
};

template<typename T>
class ZeroVisitor : public IVisitor<T>
{
public:
	void visit(T& e) { e = 0; }
};

template<typename T> class MyList : public std::list<T>
{
public:
	using std::list<T>::list;  

	void accept(IVisitor<T>* visitor)
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

	ShowVisitor<int> sv; // ��� ��Ҹ� ȭ�� ����ϴ� �湮��
	s.accept(&sv);

	ZeroVisitor<int> zv; // ��� ��Ҹ� 0���� �ϴ� �湮��
	s.accept(&zv);

	s.accept(&sv);

	// ���� ���� �湮�� �ǹ�
	// => �ܺο��� �����ϴ� ���� �ƴ϶�
	// => �ܺο����� "��ҿ� ���� ������ ����"�� �����ϰڴٴ� ��
}





