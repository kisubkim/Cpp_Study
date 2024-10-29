// 42 page ~ 

#include <iostream>
#include <cstdlib>
/*
	���
		2. strategy pattern ����
			=> Ŭ����(vector)�� ����ϴ� �˰���(�޸� �Ҵ�/����)�� �ٸ� Ŭ������ �и����ڴ� ��.

	����
		=> �޸� �Ҵ��(�Ҵ���å�� ���� Ŭ����)�� vector�� �ƴ϶� �ٸ� �����̳�(list, set, map, etc.)����
		   ����� �����ϴ�.

	����
		=> �޸� �Ҵ��� �� �� ����ϴ� �Լ��� �����Լ���.
		=> �����Լ��� �ణ ������尡 ����. --> ���� �Ҹ��� ����� ���µ�, ���� �Ҹ��� ���� ���ϰ� �߻���.
*/


/*


	�޸� �Ҵ�/������ å������ "�޸� �Ҵ��(allocator)"�� ������.
*/
template<typename T> class IAllocator
{
public:
	virtual T* allocate(std::size_t sz) = 0;
	virtual void deallocate(T* p, std::size_t sz) = 0;
	virtual ~IAllocator() {}
};



template<typename T> class MallocAllocator : public IAllocator<T>
{
public:
	T* allocate(std::size_t sz) override {
		return static_cast<T*>(malloc(sizeof(T) * sz));
	}

	void deallocate(T* p, std::size_t sz) override {
		free(p);
	}
};

template<typename T>
class vector
{
	T* buff = nullptr;

	int size;
	IAllocator<T>* alloc = nullptr;
public:
	vector(int sz, IAllocator<T>* a) : size(sz), alloc(a)
	{
		buff = alloc->allocate(sz);
		//....
	}
	~vector()
	{
		alloc->deallocate(buff, size);
		//....
	}
};

int main()
{
	//vector<int> v(4);
	vector<int> v(4, new MallocAllocator<int>());

	// ���� �޸� �Ҵ��� �ٸ� �����̳ʿ��� ����� ����.
	// list<int> s(4, new MallocAllocator<int>());
}
