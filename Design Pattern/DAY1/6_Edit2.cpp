// 33 page ~ 
#include <iostream>
#include <string>
#include <conio.h>

/*
	1. validation ��å�� ����ڰ� ������ �� �־�� �Ѵ�.

	2. ���ϴ� ���� �����Լ���...
*/

class Edit
{
	std::string data;
public:

	// ���뼺�� �������� �и�
	// => ������ �ʴ� �帧 ������ ���ϴ� ���� ã�ƶ�.
	// => ���ϴ� ���� �����Լ��� �и�.


	virtual bool validate(char c) {
		
		return true;
	}

	std::string get_data()
	{
		data.clear();

		while (1) {
			char c = _getch();

			if (c == 13) break;

			if (validate(c))		// ���� ��ȿ�� Ȯ���� �����Լ��� ���ؼ�  ==> ��� Template Method
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << '\n';
		return data;
	}
};

// ���� Edit ����ڴ� Validation ��å�� �����Ϸ��� "Edit" �Ļ�Ŭ������ ����� 
// ��ӵ� �����Լ��� override �ϸ� ��.

class NumEdit : public Edit {
public:
	bool validate(char c) override {
		return isdigit(c);
	}
};

int main()
{
	NumEdit e;
	while (1)
	{
		std::cout << e.get_data() << std::endl;
	}
}


