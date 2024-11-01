// 2_Builder
#include <iostream>
#include <string>

// �౸���� ĳ���͸� ������ ���ô�.
// ����, ������, �Źߵ��� �����Ҽ� �ֽ��ϴ�.
typedef std::string Hat;			// class Hat{}
typedef std::string Uniform;	    // class Uniform{}
typedef std::string Shoes;			// class Shoes{}
typedef std::string Character;		// class Character{}��� ����

// ������ ������ ��ü�� ���� ��, �ʿ��� ��ǰ�� ����� interface
struct IBuilder {
	virtual Hat make_hat() = 0;
	virtual Uniform make_uniform() = 0;
	virtual Shoes make_shoes() = 0;
	virtual ~IBuilder() {}
};

// ĳ���͸� ����� Ŭ����
class Director
{
	IBuilder* builder = nullptr;
public:
	void set_builder(IBuilder* b) { builder = b; }
	Character construct()
	{
		// ĳ���͸� ����� ������ ���� �մϴ�.
		Character c;
		c = c + builder->make_hat() ;
		c = c + builder->make_uniform();
		c = c + builder->make_shoes();
		return c;
	}
};

// ���� builder�� ������

class Korean : public IBuilder {
public:
	Hat make_hat() override { return "��\n"; }
	Uniform make_uniform() override { return "�Ѻ�\n"; }
	Shoes make_shoes() override { return "����\n"; }
};

class Japanese : public IBuilder {
public:
	Hat make_hat() override { return "��Ӹ�\n"; }
	Uniform make_uniform() override { return "����\n"; }
	Shoes make_shoes() override { return "�Դ�\n"; }
};

class American : public IBuilder {
public:
	Hat make_hat() override { return "�߱�����\n"; }
	Uniform make_uniform() override { return "�纹\n"; }
	Shoes make_shoes() override { return "�ȭ\n"; }
};

int main()
{
	Korean k;
	American a;
	Japanese j;

	Director d;
	d.set_builder(&k);

	Character c = d.construct();
	std::cout << c << std::endl;

	d.set_builder(&a);
	c = d.construct();
	std::cout << c << std::endl;

	d.set_builder(&j);
	c = d.construct();
	std::cout << c << std::endl;

}
