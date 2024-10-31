/*
#define MAKE_SINGLETON(classname)							\
private:													\
	classname() {}											\
	classname(const classname&) = delete;					\
	classname& operator=(const classname&) = delete;		\
public:														\
	static classname& get_instance()						\
	{														\
		static classname instance;							\
		return instance;									\
	}
private:
*/
#include "helper.h" // �� �ȿ� �� ��ũ�ΰ� �ֽ��ϴ�.

class Cursor
{
	MAKE_SINGLETON(Cursor)

	int a;
};

int main()
{
	Cursor& c = Cursor::get_instance();
}