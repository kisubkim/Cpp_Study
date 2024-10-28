#include <iostream>
#include <thread>

class Cursor
{
private:
	Cursor() {}

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;
public:

	// 아래 코드는 get_instance()가 "최초 호출될때 생성자가 호출"됩니다.
	// 멀티스레드 환경에서 안전할까요 ?
	static Cursor& get_instance()
	{
		static Cursor instance;

		return instance;
	}
};
int main()
{
	std::thread t1(&Cursor::get_instance);
	std::thread t2(&Cursor::get_instance);

	t1.join();
	t2.join();

}