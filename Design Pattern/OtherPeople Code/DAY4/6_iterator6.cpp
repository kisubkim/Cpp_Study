#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };

	// �Ʒ� for �� ������ ������ ���ô�.
	for (auto e : v)
	{
		std::cout << e << ", ";
	}

	// �� �ڵ�� �����Ϸ��� �Ʒ� ó�� �����մϴ�.(C#, java, python ��� ������ ����)
	auto first = v.begin();
	auto last = v.end();

	for (; first != last; ++first)
	{
		auto e = *first;
		//----------------------------
		std::cout << e << ", ";
	}
}