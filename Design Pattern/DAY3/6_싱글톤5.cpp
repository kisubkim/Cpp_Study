#include <iostream>
#include <mutex>

/*
	�Լ��� ������ �κп��� �ڿ� �ݳ��� �ϸ�
		1. �߰��� ���ܰ� ������ �Լ� �Ʒ� �κ��� ���� �ȵ�.
		2. �Ǽ� �� �� ����. (if ������ return �����ٵ���..) --> �ڿ� �ݳ����� �ʰ� ���ư��� ��� 
	
	RAII IDiom
		=> �ڿ��� �Ҵ�� ������ ������/�Ҹ��ڿ� �����ؾ���.
		=> Resource Acquision Is (�ڿ�������ü��) Initialization
		=> �ٽ� : �Ҹ��ڿ��� �ڿ��� �����ض�!!
*/

template<typename T> class lock_guard {
	T& mtx;
public:
	lock_guard(T& m) : mtx(m) { mtx.lock();	}
	~lock_guard() { mtx.unlock); }
};

class Cursor {
private:
	Cursor() {}

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

	static Cursor* sinstance;
	static std::mutex mtx;
public:
	/*
		�Ϲ������� �Լ� ������ �� �ڿ��� ȹ���ϰ�, �Լ��� ���� �� �� �ڿ��� �ݳ��ϴ°� �Ϲ����� ������.
	*/

	static Cursor& get_instance() {
		{
			std::lock_guard<std::mutex> g(mtx);		// 1. g�� �����ڿ��� mtx.lock()
			// 2. �������� g �ı��� �Ҹ��ڿ��� mtx.unlock()
			// ����
			//		1. ���� �߻��ص� g�� �Ҹ��ڴ� ȣ���ϰ� ���� �ڵ鷯�� �̵�
			//		2. �Ǽ��� �� ����. g�� �Ҹ��ڴ� �׻� ȣ���.
//mtx.lock();
			if (sinstance == nullptr) {
				sinstance = new Cursor;
			}
		}
		//mtx.unlock();
		return *sinstance;
	}


};
std::mutex Cursor::mtx;
Cursor* Cursor::sinstance = nullptr;

int main()
{
	Cursor& c1 = Cursor::get_instance();

}








