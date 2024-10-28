#include <iostream>
#include <list>
#include <vector>

template<typename T> class MyList : public std::list<T>
{
public:
	using std::list<T>::list;

	template<typename V>
	void accept(V visitor)
	{
		for (auto& e : *this)
			visitor(e); // visitor �� �Լ� �̰ų�
		// visitor.operator()(e)
		// ��, visitor �� () �����ڰ� �־�� �Ѵ�.
	}
};

void twice(int& e) { e *= 2; }


int main()
{
	MyList<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	s.accept(twice); // �Ϲ� �Լ� ����

	// �Ǵ� �Ʒ�ó�� ���� ǥ����
	// => ���� ǥ������ �Լ� ó�� () ȣ�� ����. 
	s.accept([](int& e) { e *= 2; });
	void (*printfp)(int& e)([](int& e) { std::cout << e << ", "; });
	s.accept(printfp);
	s.accept([](int& e) { e *= 3; });
	s.accept(printfp);
}


