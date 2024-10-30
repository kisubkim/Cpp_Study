#include <iostream>
#include <mutex>

/*
	CRTP : Curiously REcurring Template Pattern
		=> 기반 클래스에서 미래에 만들어질 파생 클래스의 이름을 사용헐 수 있게 하는 패턴.

		=> 원리 : 파생 클래스 만들 때 자신의 이름을 기반 클래스의 템플릿 인자로 전달

		=> 요즘 너무나 유행하는 기술
		C++20 의 Range 라는 표준 라이브러리가 이 기술로 작성됨.


		github.com/aosp-mirror 에 접속. (aosp : android open source project)
		system platform core Repo. 선택
		libutils/include/utils 에서 singleton.h 열어보자.
*/

template<typename T>
class Singleton {
protected:
	Singleton() {}

	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

	static T* sinstance;
	static std::mutex mtx;
public:
	static T& get_instance() {
		{
			std::lock_guard<std::mutex> g(mtx);

			if (sinstance == nullptr) {
				sinstance = new T;
			}
		}
		return *sinstance;
	}


};
// 흠...내가 보기엔 여기 이렇게 사용하는 방식을 잘 기억해 두는 게 핵심이네..
template<typename T> std::mutex Singleton<T>::mtx;
template<typename T> T* Singleton<T>::sinstance = nullptr;

/*
	Mouse class 도 위처럼 heap에 만드는 singleton으로 하고 싶다.
*/
class Mouse : public Singleton<Mouse> {

};

int main()
{
	Singleton<Mouse>& c1 = Singleton<Mouse>::get_instance();

}








