// 6_Bridge1 - 90 page
#include <iostream>

struct IMP3
{
	virtual void play() = 0;
	virtual void stop() = 0;
	virtual ~IMP3() {}
};

class IPod : public IMP3
{
public: // stringǥ�������� �������� ������ �ִٰ� �����մϴ�.
	void play() { std::cout << "Play MP3 with IPod" << std::endl; }
	void stop() { std::cout << "Stop" << std::endl; }
};

class GALAXY : public IMP3
{
public: // stringǥ�������� �������� ������ �ִٰ� �����մϴ�.
	void play() { std::cout << "Play MP3 with Galaxy" << std::endl; }
	void stop() { std::cout << "SSTOP" << std::endl; }
};

class MP3
{
	IMP3* impl;
public:
	MP3(IMP3* p = nullptr) : impl(p) {
		if (impl == nullptr)
			impl = new IPod;
	}
	void play() { impl->play(); }
	void stop() { impl->stop(); }
	void play_one_minute() {
		
		play();
		// std::this_thread::sleep_for(std::chrono::seconds(60));
		stop();
	}
};

class People
{
public:
	void use(IMP3* p) // ���� ����. ��ü �� �� �� �� �� ��
	{
		p->play();
		p->stop();

		// ����ڰ� ������ �Ʒ��� ���� �Լ��� �䱸�Ѵ�
		// p->play_one_minute(); // ���������ϸ� �������̽����� �ٲ����.. 
							  // �׷��� ����. 1�� Ÿ�̸� �÷��� �� ��ž�ϸ�ȴ�.
	}
};
int main()
{
	People p;
	IPod pod;
	GALAXY g;
	p.use(&g);
}


