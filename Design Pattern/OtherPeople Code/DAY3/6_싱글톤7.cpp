#include <iostream>
#include <thread>

class Cursor
{
private:
	Cursor() {}

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;
public:

	// �Ʒ� �ڵ�� get_instance()�� "���� ȣ��ɶ� �����ڰ� ȣ��"�˴ϴ�.
	// ��Ƽ������ ȯ�濡�� �����ұ�� ?
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