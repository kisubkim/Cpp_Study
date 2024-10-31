#include <iostream>
#include <list>
#include <vector>

// �湮�� : ��� �Ѱ��� ���� ������ �����ϴ� ��ü
class TwiceVisitor
{
public:
	void visit(int& e) { e *= 2; }
};

// STL �� �湮�� ������ ����Ǿ� ���� �ʽ��ϴ�.
// std::list �� Ȯ���ؼ� �湮�� ������ ������ ���ô�.

template<typename T> class MyList : public std::list<T>
{
public:

	// std::list �� ��� �����ڸ� MyList �� ����Ҽ� �ְ� �ش޶�.
	// => ������ ���
	using std::list<T>::list;  // std::list<T> : Ÿ���̸�
							   // list         : �Լ�(������) �̸�

	void accept(TwiceVisitor* visitor)
	{
		for (auto& e : *this)  // *this �ǹ̸� ������ ������
			visitor->visit(e);
	}
};

int main()
{
//	std::list<int> s(10, 0); // ok. std::list ���� ���� 2�� ������ ����
//	MyList<int> s(10, 0);    // error.MyList<int> ���� ���� 2�� ������ ����

	MyList<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	// �湮�ڸ� ����ϴ� �ڵ�
	// �ǹ� : "����Ѱ��� ���� ������ ����" �� �����̳ʿ� ����
	//	     �����̳ʰ� ���������� ��� ��Ҹ� �湮�ڿ��� ����
	TwiceVisitor tv;
	s.accept(&tv);
}





