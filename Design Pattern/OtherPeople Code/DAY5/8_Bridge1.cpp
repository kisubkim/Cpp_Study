// 6_Bridge1 - 90 page
#include <iostream>

struct IMP3
{
	virtual void play() = 0;
	virtual void stop() = 0;
	virtual ~IMP3(){}
};

class IPod : public IMP3
{
public: // string표현이지만 수도없는 로직이 있다고 가정합니다.
	void play() { std::cout << "Play MP3 with IPod" << std::endl; }
	void stop() { std::cout << "Stop" << std::endl; }
};

class GALAXY : public IMP3
{
public: // string표현이지만 수도없는 로직이 있다고 가정합니다.
	void play() { std::cout << "Play MP3 with Galaxy" << std::endl; }
	void stop() { std::cout << "SSTOP" << std::endl; }
};

class People
{
public:
	void use(IMP3* p) // 강한 결합. 교체 불 가 능 합 니 다
	{
		p->play();
		p->stop();

		// 사용자가 새로이 아래와 같은 함수를 요구한다
		// p->play_one_minute(); // 직접구현하면 인터페이스까지 바꿔야함.. 
							  // 그러기 싫음. 1분 타이머 플레이 후 스탑하면된다.
	}	
};
int main()
{
	People p;
	IPod pod;
	GALAXY g;
	p.use(&g);
}


