#include <string>
#include <string_view> // C++17

// �Լ� ���ڷ� ���ڿ��� �ް� �ֽ��ϴ�.(�б⸸ �ϱ� ���ؼ�)
// => �ּ��� �ڵ带 ã�� ���ô�.

// void f1(std::string s) {} // worst!!! ���� ������

void f2(const std::string& s) {} // good ������ best �� �ƴ�.!



void f3(std::string_view  sv) {}


int main()
{
	std::string s = "abcd";

	// �Ʒ� �ڵ�� ū ���̰� �����ϴ�
	f2(s);
	f3(s);

	// �Ʒ� �ڵ尡 �ٽ� �Դϴ�
	// => ���ڷ� literal �� ���� ������ ���.

	f2("hello"); // �� �� ��Ʈ����ü�� ��������	
	f3("hello"); // �� �� �׳� ������� ��������.
	//�׷��� �б����� ��ü�� ���鋚�� string_View�� ���°��� �������̴�.
}