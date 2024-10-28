#include <iostream>
#include <mutex>


template<typename T>
class Singleton
{
protected:
	Singleton() {}

	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

	static T* sinstance;     // <<== !!
	static std::mutex mtx;
public:
	static T& get_instance() // <<== !!
	{
		std::lock_guard<std::mutex> g(mtx);

		if (sinstance == nullptr)
			sinstance = new T; // <<== !!

		return *sinstance;
	}
};
template<typename T> T* Singleton<T>::sinstance = nullptr;  // <<== !!
template<typename T> std::mutex Singleton<T>::mtx;

// Mouse 클래스도 위와 같은 힙에 만드는 싱글톤으로 하고 싶다
class Mouse : public Singleton<Mouse>
{
public:
	void print() {
		std::cout << "mouse haha";
	}
};


int main()
{
	Mouse& c1 = Mouse::get_instance();
	c1.print();
}
