#include <iostream>
#include <mutex>

// �Լ��� ������ �κп��� �ڿ� �ݳ��� �ϸ�
// 1. �߰��� ���� �߻���, �Լ� �Ʒ� �κ��� ���� �ȵ�
// 2. �Ǽ� �Ҽ� ����. "if (����) return"  �ڿ� �ݳ����ϰ� ���ư�.

// RAII IDioms
// => �ڿ��� �Ҵ�� ������ ������/�Ҹ��ڿ� �����ؾ� �մϴ�.
// => Resource Acquision Is (�ڿ�������ü��) Initialization
// => �ٽ� : �Ҹ��ڿ��� �ڿ��� �����ض�!!

template<typename T> class lock_guard
{
	T& mtx;
public:
	lock_guard(T& m) : mtx(m) { mtx.lock(); }
	~lock_guard()			  { mtx.unlock(); }
};



class Cursor
{
private:
	Cursor() {}
	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

	static Cursor* sinstance;
	static std::mutex mtx;
public:

	static Cursor& get_instance()
	{
		std::lock_guard<std::mutex> g(mtx);
//		lock_guard<std::mutex> g(mtx); // 1. g�� �����ڿ��� mtx.lock()
										// 2. �������� g �ı��� �Ҹ��ڿ��� mtx.unlock()
										// ���� 1. ���� �߻��ص� g�� �Ҹ��ڴ� ȣ���ϰ�
										//	      ���� �ڵ鷯�� �̵�
										// ���� 2. �Ǽ��Ҽ� ����. g�� �Ҹ��ڴ� �׻�ȣ��
//		mtx.lock();

		if (sinstance == nullptr)
			sinstance = new Cursor;
	
	//	if (����) return 0; // �̰�쵵 g�� �Ҹ��� ȣ��..

//		mtx.unlock();

		return *sinstance;
	}






};
Cursor* Cursor::sinstance = nullptr;
std::mutex Cursor::mtx;


int main()
{
	Cursor& c1 = Cursor::get_instance();

}






