// 33 page ~ 
#include <iostream>
#include <string>
#include <conio.h>

// validate ��å�� ����ڰ� ������ �� �ֵ��� �ؾ� �Ѵ�.

class Edit
{
	std::string data;
public:
	virtual bool validate(char c) {  // ���ø� �޼ҵ� ���� ��ü���� Ʋ�� �״�εΰ� validate�Լ��� �����ߴ�
		return true;
	}
	std::string get_data()
	{
		data.clear();
		while (1)
		{
			char c = _getch();
			if (c == 13) break; // enter Ű ���� ���
			if (validate(c)) {
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << "\n";
		return data;
	}
};

class UserEdit : public Edit {
	bool validate(char c) override {
		return isdigit(c);
	}
};

int main()
{
	UserEdit e;
	while (1)
	{
		std::cout << e.get_data() << std::endl;
	}
}


