#include <vector>
#include <iostream>

template<typename T>
class take_view {
	T& c;
	int count;
public:
	take_view(T& c, int count) : c(c), count(count) {}

	auto begin() { return c.begin(); }
	auto end() { return c.begin() + count; }
};


/*

	�Ʒ� �ڵ忡�� vector�� 10���� �ڿ��� ������ ����.
	[1,2,3,4,5,6,7,8,9,10]

	take_view �� & �� count�� ����.
	c ----> [1,2,3,4,5,6,7,8,9,10]    // c �� vector �� ����Ű�� ������
	begin() �� end()�� �ٽ� �����Կ� ����..begin()�� ����.
	������ end() �� begin()���� count ��ŭ�� �̵��� �κ��� end()�� ������.

	for�� ��� �׻� begin() ���� end() ���� �ݺ��ϱ� ������ count ��ŭ�� ���Ե�.

*/

int main() {
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	take_view tv(v, 3);		// c++17���ʹ� type�� ���� �ȾƵ� �߷��� �����ؼ� <int>�� ����

	//for (auto e : v) {
	for (auto e : tv) {		// ������ ����.
		std::cout << e << ", ";
	}
	std::cout << "\n";



	auto first = v.begin();
	auto last = v.end();

	for (; first != last; ++first) {
		auto e = *first;
		//--------------
		std::cout << e << ",";		// ����� code
	}
}