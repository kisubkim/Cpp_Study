// 7 page

#include <iostream>

class Animal
{
public:
	int age;
	virtual void cry() {}
};
class Dog : public Animal
{
public:
	int color;
};
int main()
{
	Animal a;
	Dog d;
	Dog* p1 = &d;
	//Animal* p = &a;
	Animal* p = &d;

	Dog* dog = static_cast<Dog*>(p);
	// static cast : ������ �ð� ĳ����. ����� ������� ����.
	//				 ������ �ð����� p�� ����Ű�� ���� ������ �� ����.
	//				 �׷��� ������ casting �� ������. (��Ŵ� ������ å��)
	// Dynamic cast : ��Ÿ�� �ð�. ���� �� ������� ����.
	//				  ����ð��� p�� ����Ű�� ���� �����ؼ� Dog�� �ƴϸ� 0 ����.
	//				  class, structor�� �����Լ��� ������ �����Լ� table�� �ش� type�� ���� ������ ��ϵȴ�.
	//					��, dynamic_cast�� ����Ϸ��� "��ü ��򰡿� Ÿ�������� ����ؾ� �Ѵ�"
	//					c++�� �����Լ� ���̺� Ÿ�� ������ ���. ���� dynamic_cast�� �����Լ��� �ִ� Ÿ�Ը� ����.

	std::cout << dog << std::endl;

	dog->color = 10;		// ���� p�� ����Ű�� ���� Dog�� �ƴϸ� �� �ڵ�� Error���� ������ ���ᵵ �� �� ����.

	Dog* dog2 = dynamic_cast<Dog*>(p);
	std::cout << dog2 << std::endl;

}











