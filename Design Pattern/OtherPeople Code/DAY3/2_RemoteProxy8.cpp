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
	// C++ ǥ�ؿ� std::shared_ptr �̶�� ����Ʈ �����Ͱ� �ִµ�..
	// sp ������ ����, �̰��� ����ϸ� �ȵǳ��� ??

	std::shared_ptr<int> p1(new int);	// ok
	// p1�� ���������� �Ҵ�� �޸� �ּҺ���
	// ��������� �����ϴ� ��ɵ� ����.
	// p1 �ı��ɶ� �Ҹ��ڿ��� ��������� ����
	// 0 �̵Ǹ� delete
// �׷���, ���ڵ�� "�������Ͽ��� new �ϰ�
//				   "�������Ͽ��� delete �Ѱ�"

	std::shared_ptr<ICalc> p2(load_proxy()); // �̷��� �ϸ� �ȵ˴ϴ�.
	// DLL ���� new �Ѱ��� ���������� delete �Ѱ�

	sp<ICalc> p3(load_proxy());
	// �Ҹ��ڿ��� delete �� �ƴ� Release() ȣ��
	// Release �� DLL �ȿ� �ְ�, �ű⼭ delete 

}