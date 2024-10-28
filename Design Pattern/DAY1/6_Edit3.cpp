// 33 page ~ 
#include <iostream>
#include <string>
#include <conio.h>

/*
	변하는 것을 분리하는 2가지 기술
		1. 변하는 것을 가상함수로 - template method pattern, edit2.cpp
		2. 변하는 것을 다른 클래스로 - strategy pattern, edit3.cpp


	Validation 정책을 별도의 class로 설계
		=> 교체 가능해야 함으로 "약한 결합"
		=> 인터페이스를 먼저 설계
*/

struct IValidator {
	virtual bool validate(const std::string& s, char c) = 0;
	virtual bool is_complete(const std::string& s) { return true; }

	virtual ~IValidator() {}
};

class Edit
{
	std::string data;
	IValidator* val = nullptr;
public:
	void set_validator(IValidator* v) { val = v; }

	std::string get_data()
	{
		data.clear();

		while (1) {
			char c = _getch();
			if (c == 13 && (val == nullptr || val->is_complete(data))) break;

			// 이거 if 문에서는 앞쪽에 적은게 첨으면 무조건 그냥 뒤에꺼 무시하는게 || 연산자임
			// 아래는 val 이 있으면 무조건 다 입력받고, 있으면 검사하는 내용임.
			if ( val == nullptr || val->validate(data, c))		// 유효성 여부를 다른 객체에 위임.
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << '\n';
		return data;
	}
};

// 이제 Edit에서 사용할 다양한 Validator 객체를 만들면 됨.
class LimitDigitValidator : public IValidator {
	int limit;
public:
	LimitDigitValidator(int n) : limit(n) {}

	bool validate(const std::string& s, char c) override {
		return s.size() < limit && isdigit(c);
	}

	bool is_complete(const std::string& s) override {
		return s.size() == limit;
	}

};

/*
class email_validator : public IValidator { };
class pinnumber_validator : public IValidator { };
class phonenumber_validator : public IValidator { };
*/

int main()
{
	Edit e;
	LimitDigitValidator v(5);
	e.set_validator(&v);		// 요게 핵심.

	while (1)
	{
		std::cout << e.get_data() << std::endl;
	}
}


