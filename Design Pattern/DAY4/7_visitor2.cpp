#include <iostream>
#include <list>
#include <vector>

/*
	�湮��(visitor)  : ��� �Ѱ��� ���� ������ �����ϴ� ��ü
*/

template<typename T>
struct IVisitor {
	virtual void visit(T& e) = 0;
};

template<typename T>
class TwiceVisitor : public IVisitor<T> {
public :
	void visit(T& e) override { e *= 2; }
};

template<typename T>
class ShowVisitor : public IVisitor<T> {
	void visit(T& e) override { e *= 2; }
};

template<typename T>
struct IContainter {
	virtual void accept(IVisitor<T>* visitor) = 0;
};

template<typename T>
class MyList : public std::list<T>, public IContainter<T> {
public:
	// **** ������ ��� ����ؾ���. ****
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

	// visitor �� ����ϴ� �ڵ�
	//		=> �ǹ� : "��� �Ѱ��� ���� ������ ����" �� container �� ����
	//				 container �� ���������� ��� ��Ҹ� �湮�ڿ��� ����
	TwiceVisitor<int> tv;
	s.accept(&tv);
}





