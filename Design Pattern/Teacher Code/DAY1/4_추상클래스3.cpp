//1_�߻�Ŭ����2.cpp
#include <iostream>


/*
* �Ʒ� 2���� �� ȥ��Ǿ� ���ǰ� �ϴµ� �ణ�� �������� ����.
*		Abstract Class : ���Ѿ� �ϴ� ��Ģ(pure virtual function) + �ٸ� ���
*		Interface : ���Ѿ� �ϴ� ��Ģ (pure virtual function)
*	
*/

// ���⼭ Interface �ǽ��� �غ���.
// ��ü���� Camera�� ���� ������ ���� ��� ī�޶� ���Ѿ� �ϴ� ��Ģ�� ���� �����Ѵ�.

/*
* ��Ģ
	1. "��� ī�޶�� �Ʒ� Ŭ������ ���� �Ļ�" �̶�� ǥ������ ����
	   "��� ī�޶�� �Ʒ� �������̽��� �����ؾ� �Ѵ�" ��� ǥ��.
*/	


// c++ ���� struct�� class�� ���̴� ������ public, private ������ ����.
// �׷��� ���� ������ �����ؼ� ���� ������ public�� ������ struct�� ����� �ϱ⵵ ��.
// class : ���������� �����ϸ� private
// struct : ���������� �����ϸ� public

// ������ �����ߴ� ����
#define interface struct
// �䷸�� �س���, �Ʒ����� class ��ſ� class ���.

class ICamera {
public :
	virtual void take() = 0;
	virtual ~ICamera() {}			// Interface�� �ᱹ ��� Ŭ������.
									// ���� �Ҹ��ڸ� �ݵ�� "virtual"�� �����ؾ���.
};

// ���� class�� Interface��� �� �� �� �ְ�, ���࿡ member variable�� ������ abstract class ��.
// Java, C# : ������ Ű���� (interface, class) ����. --> ���� c++ó�� ȥ���ؼ� ���� error��
// C++ : ������ Ű���� ����, �߻�Ŭ���� �������θ� ��� ����� ��.

/*
	���Ѱ��� (Tightly Coupling)
		=> �ϳ��� Ŭ������ �ٸ� Ŭ���� ��� �� "Ŭ�����̸��� ����" ����ϴ� ��
		=> People::use_camera(Camera*) �� ���� ����.
		=> ��ü �Ұ����� ������ ������.

	���Ѱ��� (Loosely Coupling)
		=> �ϳ��� Ŭ������ �ٸ� Ŭ���� ��� �� "��Ģ�� ���� Interface �̸�" �� ���ؼ� ���� �ϴ� ��
		=> People::use_camera(ICamera*) �� ���� ����.
		=> ��ü ������ ������ ������.
*/


// ���� ī�޶� ���, ��Ģ�� �ִ�.
// ����ϴ� �ڵ带 �ۼ��� ���� ����.
// ��Ģ��θ� ����ϸ� ��.

class People {
public :
	void use_camera(ICamera* c) { c->take(); }		// abstract�� ��ü�� ���� �� ������ pointer�� ���� ���� ����.
};

class Camera : public ICamera
{
public:
	void take() override { std::cout << "Take Picture" << std::endl; }
};

class HDCamera : public ICamera
{
public:
	void take() override { std::cout << "Take HD Picture" << std::endl; }
};

class UHDCamera : public ICamera
{
public:
	void take() override { std::cout << "Take UHD Picture" << std::endl; }
};

int main()
{
	People p;
	Camera c;
	p.use_camera(&c);

	HDCamera hc;
	p.use_camera(&hc);

	UHDCamera uhc;
	p.use_camera(&uhc);
}





