#include <iostream>
#include <cstdlib> // malloc

// ��� #2. strategy ���� ����
// => Ŭ����(vector)�� ����ϴ� �˰���(�޸��Ҵ�/����)�� �ٸ� Ŭ������
//    �и����ڴ� ��


// ���� 
// => �޸� �Ҵ��(�Ҵ���å�� ���� Ŭ����)�� vector �� �ƴ϶� 
//    �ٸ� �����̳�(list, set, map ��) ���� ��밡���մϴ�.

// ���� 
// => �޸� �Ҵ��� �Ҷ� ����ϴ� �Լ��� �����Լ� �Դϴ�.
// => �����Լ��� �ణ�� ������尡 �ֽ��ϴ�.


// �޸� �Ҵ�/������ å������ "�޸� �Ҵ��(allocator)" �� ����� ���ô�.

template<typename T> struct IAllocator
{
	virtual T* allocate(std::size_t sz) = 0;
	virtual void deallocate(T* p, std::size_t sz) = 0;

	virtual ~IAllocator() {}
};


template<typename T> class MallocAllocator : public IAllocator<T>
{
public:
	T* allocate(std::size_t sz) override
	{
		return static_cast<T*>(malloc(sizeof(T) * sz));
	}
	void deallocate(T* p, std::size_t sz) override
	{
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
//	vector<int> v(4);
	vector<int> v(4, new MallocAllocator<int>() );

	// ���� �޸� �Ҵ��� �ٸ� �����̳ʿ��� ��밡���մϴ�.
//	list<int> s(4, new MallocAllocator<int>() );
}

