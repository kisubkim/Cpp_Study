#include <iostream>
#include <list>
#include <vector>

template<typename T>
struct IVisitor {
	virtual void visit(T&) = 0;
	virtual ~IVisitor() {}
};

template<typename T>
class TwiceVisitor : public IVisitor<T> {
public :
	void visit(T& e) override { e *= 2; }
};

template<typename T>
class ShowVisitor : public IVisitor<T> {
	void visit(T& visitor) override {
		std::cout << visitor << " ";
	}
};

template<typename T>
class ZeroVisitor : public IVisitor<T> {
	void visit(T& visitor) override {
		visitor = 0;
	}
};

template<typename T>
struct IContainter {
	virtual void accept(IVisitor<T>*) = 0;
	virtual ~IContainter() {}
};

template<typename T>
class MyList : public std::list<T>, public IContainter<T> {
public:
	using std::list<T>::list;

	void accept(IVisitor<T>* visitor) override {
		for (auto& e : *this) {
			visitor->visit(e);
		}
	}
};

int main()
{
	//std::list<int> s(10, 0);		// ok. std::list ���� ���� 2�� ������ ����.

	MyList<int> s = { 1,2,3,4,5,6,7,8,9,10 };		// error MyList<int> ���� ���� 2�� �����ڰ� ����.

	ShowVisitor<int> sv;
	s.accept(&sv);
	std::cout << std::endl;

	TwiceVisitor<int> tv;
	s.accept(&tv);
	s.accept(&sv);
	std::cout << std::endl;

	ZeroVisitor<int> zv;		// ��� ��Ҹ� 0���� �ϴ� �湮��.
	s.accept(&zv);
	s.accept(&sv);
	std::cout << std::endl;
	
	/*
		������� �湮�� �ǹ�
			=> �ܺο��� �����ϴ� ���� �ƴ϶� �ܺο��� "��ҿ� ���� ������ ���Ǹ� �����ϰڴ�"�� ��.
	*/
}





