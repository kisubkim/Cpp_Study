// 7 page
#include <iostream>
using namespace std;
class Animal
{
public:
	int age;
	virtual ~Animal() {} // ���� �Ҹ��� => ���� �ð��� ���..
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

	Animal* pa = &a;
	//dynamic casting - type�� runtime�� �˾ƺ���
	//static casting - ������Ÿ�ӿ� �ڵ忡 ���� �����Ϸ��� Ÿ���� �´��� �������� �ʰ� ������ ��� -> ���� �� overhead 0

	Dog* p = static_cast<Dog*>(pa); // = Dog* p = (Dog*)(pa);
	cout << pa << endl;
	cout << p << endl;

	// p->color = 22; // error undefined
	
	Dog* p1 = dynamic_cast<Dog*>(pa); // static���� ������� �ʾƼ� �ϴ��� ����. -> �����Լ� ����� ���⿡ �����Լ� ���̺� ������ Ÿ���� �� �� ����. �����Լ� ��Ʈ���� Ȯ�ξ�

	cout << p1 << endl; // Ÿ���� �߸��Ǿ� �ּҰ� 0���� ���ͺ�����
}