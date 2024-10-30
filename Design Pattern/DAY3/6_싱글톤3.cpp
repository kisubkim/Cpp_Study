#include <iostream>


/*
	오직 한개의 객체를 힙에 만드는 모델.
		=> 전역 Data 올라가는 Memory 공간이 작을 경우 Heap 에다가 올려서 사용.
*/

class Cursor {
private:
	Cursor() {}

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

	static Cursor* sinstance;
public:
	static Cursor& get_instance() {
		if (sinstance == nullptr) {
			sinstance = new Cursor;
		}
		return *sinstance;
	}
};

Cursor* Cursor::sinstance = nullptr;		// static member data는 외부 선언이 필요함. (in C++)

int main()
{
	Cursor& c1 = Cursor::get_instance();

}








