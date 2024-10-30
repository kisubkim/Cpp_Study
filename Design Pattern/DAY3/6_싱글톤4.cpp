#include <iostream>
#include <mutex>

/*
	MultiThread 환경에서도 오직 한개만 만들수 있도록 동기화.
*/

class Cursor {
private:
	Cursor() {}

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

	static Cursor* sinstance;
	static std::mutex mtx;
public:
	/*
		현재 code 는 single thread 에서는 안전한데...multithread 환경에서는??
	*/

	static Cursor& get_instance() {
		mtx.lock();
		if (sinstance == nullptr) {
			sinstance = new Cursor;
		}
		mtx.unlock();
		return *sinstance;
	}
};
std::mutex Cursor::mtx;
Cursor* Cursor::sinstance = nullptr;		// static member data는 외부 선언이 필요함. (in C++)

int main()
{
	Cursor& c1 = Cursor::get_instance();

}








