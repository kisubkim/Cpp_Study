#include <iostream>
#include <list>
#include <vector>

// ���ø��� ���� ǥ������ ����� �湮��

template<typename T> class MyList : public std::list<T>
{
public:
	using std::list<T>::list;

	template<typename V>
	void accept(V v)
	{
		for (auto& e : *this)
			v(e);
	}
};

void foo(int& e) { e *= 2; }

int main()
{
	MyList<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	s.accept(foo);	// �Լ��� ���� �湮��

	s.accept([](int& e) { e *= 2; });	// ���� ǥ���� ���
	s.accept([](int& e) { std::cout << e << ", "; });
}


