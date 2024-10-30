#include <iostream>

/*
	"static member data" VS "static local variable"

	static ���� ����(static local variable) : �Լ��� ó�� ȣ�� ���� �� �������. ȣ������ ������ Cursor() ������ ȣ����� ����.
											=> ������ �ʱ�ȭ (�ʿ��� ���� �ʱ�ȭ)

	static ��� ������ (static member data) : main �Լ��� ����Ǳ� ���� Cursor ������ ȣ��. ��, ������� �ʾƵ� �������.
											=> main ���� ���� ������������ ���� table�� �ֱ� ���ؼ� �����.
											(�� �Ĳ��ϰ� ���� ��Ȯ�� ���� ������������� ��Ȯ���� ����)
											=> �̸� �ʱ�ȭ (�׳� ���� �ʱ�ȭ)
*/

class Cursor {
private:
	Cursor() { std::cout << "Cursor()" << std::endl; }
	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

	//Cursor instance;		// Error. �׳��ϸ� ��� ������ ���� �Ұ���. size�� �˾Ƴ��� ���ؼ� ��� �ڽ�Ÿ������ ���� ��.
	static Cursor instance;		// static member data�� �ڽ� Ÿ�� ���� ����
public:
	static Cursor& get_instance() {
	//	static Cursor instance;
		return instance;
	}
};

Cursor Cursor::instance;		// static member data �� �ܺ� ���� �ʿ�.

int main() {
	std::cout << "=============" << std::endl;
	//Cursor& c1 = Cursor::get_instance();
}





