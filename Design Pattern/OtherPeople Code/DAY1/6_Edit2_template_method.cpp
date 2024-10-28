// 33 page ~ 
#include <iostream>
#include <string>
#include <conio.h>

// validate 정책은 사용자가 변경할 수 있도록 해야 한다.

class Edit
{
	std::string data;
public:
	virtual bool validate(char c) {  // 템플릿 메소드 패턴 전체적인 틀은 그대로두고 validate함수만 변경했다
		return true;
	}
	std::string get_data()
	{
		data.clear();
		while (1)
		{
			char c = _getch();
			if (c == 13) break; // enter 키 누른 경우
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


