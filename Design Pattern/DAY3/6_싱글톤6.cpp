#include <iostream>
#include <mutex>

/*
	CRTP : Curiously REcurring Template Pattern
		=> ��� Ŭ�������� �̷��� ������� �Ļ� Ŭ������ �̸��� ����� �� �ְ� �ϴ� ����.

		=> ���� : �Ļ� Ŭ���� ���� �� �ڽ��� �̸��� ��� Ŭ������ ���ø� ���ڷ� ����

		=> ���� �ʹ��� �����ϴ� ���
		C++20 �� Range ��� ǥ�� ���̺귯���� �� ����� �ۼ���.


		github.com/aosp-mirror �� ����. (aosp : android open source project)
		system platform core Repo. ����
		libutils/include/utils ���� singleton.h �����.
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
// ��...���� ���⿣ ���� �̷��� ����ϴ� ����� �� ����� �δ� �� �ٽ��̳�..
template<typename T> std::mutex Singleton<T>::mtx;
template<typename T> T* Singleton<T>::sinstance = nullptr;

/*
	Mouse class �� ��ó�� heap�� ����� singleton���� �ϰ� �ʹ�.
*/
class Mouse : public Singleton<Mouse> {

};

int main()
{
	Singleton<Mouse>& c1 = Singleton<Mouse>::get_instance();

}








