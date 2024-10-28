// 2_Builder
#include <iostream>
#include <string>

// �౸���� ĳ���͸� ������ ���ô�.
// ����, ������, �Źߵ��� �����Ҽ� �ֽ��ϴ�.
typedef std::string Hat;			// class Hat{}
typedef std::string Uniform;	    // class Uniform{}
typedef std::string Shoes;			// class Shoes{}
typedef std::string Character;		// class Character{}��� ����

// ĳ���͸� ����� Ŭ����

struct IBuilder {
	virtual void make_hat() = 0;
	virtual void make_uniform() = 0;
	virtual void make_shoes() = 0;
	virtual Character get_result() = 0;
	virtual ~IBuilder(){}
};

class Director
{
	IBuilder* builder = nullptr;
public:
	void set_builder(IBuilder* p) { builder = p; }
	Character construct()
	{
		// ĳ���͸� ����� ������ ���� �մϴ�.
		//builder->make_hat();
		builder->make_uniform();
		builder->make_shoes();

		return builder->get_result();
	}
};

class Korean : public IBuilder {
	Character player;
public:
	void make_hat() override { player += "�� \\"; }
	void make_uniform() override { player += "�Ѻ� \\"; }
	void make_shoes() override { player += "�ɽ� \\"; }

	Character get_result() override { return player; }
};

class Japaness : public IBuilder {
	Character player;
public: 
	void make_hat() override { player += "�繫���̰� \\ "; }
	void make_uniform() override { player += "�繫���̿� \\ "; }
	void make_shoes() override { player += "������ \\ "; }

	Character get_result() override { return player; }
};

int main()
{
	Director d;
	Korean k;
	Japaness j;

	d.set_builder(&k);
	Character c = d.construct();
	std::cout << c << std::endl;


	d.set_builder(&j);
	c = d.construct();
	std::cout << c << std::endl;
}