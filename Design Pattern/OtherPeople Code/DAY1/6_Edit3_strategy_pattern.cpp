// 33 page ~ 
#include <iostream>
#include <string>
#include <conio.h>

// ���ϴ� ���� �����Լ��� -> template method pattern
// ���ϴ� ���� �ٸ� Ŭ������ -> strategy pattern

// ���ؾ� �Ѵ� ->  ��ü �����ؾ� �Ѵ� -> ���� ����
// �������̽�

struct IValidator
{
	virtual bool validate(const std::string& data, char c) = 0;
	virtual bool is_complete(const std::string& data) { return true; }
	virtual ~IValidator() {}
};

//�ֹι�ȣ Ȯ���ϴ� �� ������


//�ٸ� edit�� ��쿡��, validation�� ��������. �� �ٸ� Ŭ������ ��å ������ ���ؼ�, strategy Pattern�� �� ���ٰ� �� �� ����. 
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
			if (c == 13 && (val == nullptr || val->is_complete(data))) break; //enter Ű ���� ���
			// ��ȿ�� üũ������ ���Է¹�����
			if (val == nullptr || val->validate(data,c)) {             // �ٸ� Ŭ������ ������ strategy ������. ��å Ŭ���� ��������~
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


