// 6_Bridge1 - 90 page
#include <iostream>


struct IMP3 {
	virtual void play() = 0;
	virtual void stop() = 0;
};

class IPod : public IMP3
{
public:
	void play() override { std::cout << "Play MP3 with IPod" << std::endl; }
	void stop() override { std::cout << "Stop" << std::endl; }
};

/*
	IMP3 을 직접 사용하게 되면
		=> 요구사항이 자주 발생하게 되면 IMP3 자체가 수정되어야 함.
		=> Interface의 변경은 아주 어려운 작업

		그래서 사용자들이 IMP3이 아닌 중간층을 사용하게 함.

	Bridge의 의도는 Update임.
*/

class MP3 {
	IMP3* impl;
public:
	MP3(IMP3* p = nullptr) : impl(p) {
		if (impl == nullptr) {
			impl = new IPod;
		}
	}

	// 실제 MP3 관련 모든 기능을 "구현층"을 사용하게 함.
	// => 실제 음악 기능 구현은 아주 복잡한 코드
	void play() { impl->play(); }
	void stop() { impl->stop(); }

	// 사용자들에게 새로운 서비스(interface 변경)를 제공하지만
	// 구현층은 수정될 필요 없음.
	//		=> 구현과 Interface(추상층)의 독립된 update
	void play_one_minute() {
		impl->play();

		// 1분 timer 설치후.
		impl->stop();
	}
};

/*
	실제 사용자는 "구현이 아닌 추상층(간접층)"을 사용하게 됨.
*/

class People
{
public:
	//void use(IPod* p)		// 현재 상태는 한 제품만 쓰겠다는 이야기 (강한결합)..교체하려면 상위 인터페이스 필요.
	//void use(IMP3* p)		// 약한 결합. 교체가능. 다른 제품 사용가능.
	void use(MP3* p)		// 실제 구현이 아닌 간접층.
	{
		p->play();
		p->stop();

		// 요구조건이 생김.(1분 미리 듣기) 
		p->play_one_minute();
	}
};
int main()
{
	People p;
	IPod pod;
	p.use(&pod);
}


