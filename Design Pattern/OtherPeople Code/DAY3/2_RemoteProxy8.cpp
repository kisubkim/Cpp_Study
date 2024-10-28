#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"
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
	T& operator*() { return*obj; }
};
int main()
{
	// C++ 표준에 std::shared_ptr 이라는 스마트 포인터가 있는데..
	// sp 만들지 말고, 이것을 사용하면 안되나요 ??

	std::shared_ptr<int> p1(new int);	// ok
	// p1이 내부적으루 할당된 메모리 주소보관
	// 참조계수로 관리하는 기능도 있음.
	// p1 파괴될때 소멸자에서 참조계수를 빼고
	// 0 이되면 delete
// 그런데, 이코드는 "실행파일에서 new 하고
//				   "실행파일에서 delete 한것"

	std::shared_ptr<ICalc> p2(load_proxy()); // 이렇게 하면 안됩니다.
	// DLL 에서 new 한것을 실행파일이 delete 한것

	sp<ICalc> p3(load_proxy());
	// 소멸자에서 delete 가 아닌 Release() 호출
	// Release 는 DLL 안에 있고, 거기서 delete 

}