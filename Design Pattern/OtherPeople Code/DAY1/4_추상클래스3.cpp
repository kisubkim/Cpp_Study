//1_추상클래스3.cpp
#include <iostream>


class Camera
{
public:
	virtual void take() = 0;
	int abc = 1;
protected:
	int cbd = 1;
private:
	int ncp = 1;
};


class People
{
public:
	void use_camera(Camera* p) { p->take(); }
protected:
	int cbf = 1;
};

class HDCamera : public Camera
{
public:
	void take() override { std::cout << "Take HD Picture" << std::endl; cbd = 2; }
};

class QHDCamera : public Camera
{
public:
	void take() override { std::cout << "Take QHD Picture" << std::endl; }
};

int main()
{
	People p;
	HDCamera H;
	QHDCamera Q;
	p.use_camera(&H);
	p.use_camera(&Q);
}




