// 2_Builder
#include <iostream>
#include <string>

// 축구게임 캐릭터를 생각해 봅시다.
// 모자, 유니폼, 신발등을 변경할수 있습니다.
typedef std::string Hat;			// class Hat{}
typedef std::string Uniform;	    // class Uniform{}
typedef std::string Shoes;			// class Shoes{}
typedef std::string Character;		// class Character{}라고 가정

// 캐릭터를 만드는 클래스

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
		// 캐릭터를 만드는 공정은 동일 합니다.
		//builder->make_hat();
		builder->make_uniform();
		builder->make_shoes();

		return builder->get_result();
	}
};

class Korean : public IBuilder {
	Character player;
public:
	void make_hat() override { player += "갓 \\"; }
	void make_uniform() override { player += "한복 \\"; }
	void make_shoes() override { player += "꽃신 \\"; }

	Character get_result() override { return player; }
};

class Japaness : public IBuilder {
	Character player;
public: 
	void make_hat() override { player += "사무라이갓 \\ "; }
	void make_uniform() override { player += "사무라이옷 \\ "; }
	void make_shoes() override { player += "나막신 \\ "; }

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