// 33 page ~ 
#include <iostream>
#include <string>
#include <conio.h>

// 변하는 것을 가상함수로 -> template method pattern
// 변하는 것을 다른 클래스로 -> strategy pattern

// 변해야 한다 ->  교체 가능해야 한다 -> 약한 결합
// 인터페이스

struct IValidator
{
	virtual bool validate(const std::string& data, char c) = 0;
	virtual bool is_complete(const std::string& data) { return true; }
	virtual ~IValidator() {}
};

//주민번호 확인하는 거 만들어보자


//다른 edit의 경우에도, validation을 쓸수있음. 즉 다른 클래스와 정책 공유를 위해서, strategy Pattern이 더 좋다고 할 수 있음. 
struct citizenshipValidator :IValidator {
public:
	int limit;

	citizenshipValidator(int v = 13) : limit(v) {}

	bool validate(const std::string& s, char c) override
	{
		return isdigit(c) && (limit == 9999 || s.size() < limit);
	}
	bool is_complete(const std::string& data) { return data.length() >= limit; }
	~citizenshipValidator() {}
};

class Edit
{
	std::string data;
	IValidator* val = nullptr;
public:
	void set_validator(IValidator* v) { val = v; };
	std::string get_data()
	{
		data.clear();
		while (1)
		{
			char c = _getch();
			if (c == 13 && (val == nullptr || val->is_complete(data))) break; //enter 키 누른 경우
			// 유효성 체크없으면 다입력받을게
			if (val == nullptr || val->validate(data,c)) {             // 다른 클래스로 뽑으면 strategy 패턴임. 정책 클래스 만들어보리기~
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << "\n";
		return data;
	}
};

int main()
{
	Edit e;
	citizenshipValidator* a = new citizenshipValidator(6);
	e.set_validator(a);
	while (1)
	{

		std::cout << e.get_data() << std::endl;
	}
}


