#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

// raw pointer
// => 객체가 아닙니다.
// => 생성자/소멸자/복사생성자/대입연산자 개념이 없습니다.

// proxy
// => 다양한 이유로 대신할것을 만드는 패턴.  -> smart pointer임 지금 하는것이
template<typename T>
class sp
{
	T* obj;
public:
	sp(T* p = nullptr) : obj(p)
	{
		if (obj != nullptr) obj->AddRef();
	}

	sp(const sp& other) :obj(other.obj) {
		if (obj != nullptr) obj->AddRef();
	}

	~sp()
	{
		if (obj != nullptr) obj->Release();
	}

	T* operator->() { return obj; }
	T& operator*() { return* obj; }
};

int main()
{
	//	ICalc* calc1 = load_proxy();
	sp<ICalc> calc1 = load_proxy(); // == sp<ICalc> calc2(load_proxy());
	sp<ICalc> calc2 = calc1; // 복사생성자

	calc1->Add(10, 20);
	(*calc1).Add(10, 20);
	calc2->Add(10, 20);

}

