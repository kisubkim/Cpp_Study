#include <string>
#include <string_view> // C++17

int main()
{
	// std::string �� ���ڿ��� "����" �մϴ�.
	std::string s = "abcd";

	// #1.
	std::string      ss = s; // s�� ���ڿ��� ss�� ������ ����.(���� ����)
	std::string_view sv = s; // sv�� ss�� ���ڿ��� ����Ŵ(const char* )

	// #2. literal �� �ʱ�ȭ �ϴ� ���
	// => ���α׷� ����� "abcd" �� �ϴ� ����޸�(.rdata)�� �ִ�!!
	std::string      ss1 = "abcd"; // abcd�� ���纻�� ���� ss1�� ����
	std::string_view sv1 = "abcd"; // ��� �޸𸮿� �ִ� "abcd" �� ����Ų��
	// const char* �� ����
}