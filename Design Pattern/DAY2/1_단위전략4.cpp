// 42 page ~ 

#include <iostream>
#include <cstdlib>
/*
	���
		3. Policy Base Design (���� ����)
			=> ��åŬ������ "Interface"�� ����ؼ� ��ü �ϴ� ���� �ƴ϶� template ���ڷ� ��ü�ϴ� ���
*/


/*
	strategy VS policy base design
		=> ��� Ŭ������ ����ϴ� � ��å�� "�ٸ� Ŭ������ �и�" ���ڴ� ��

		=> �׷���, ��å Ŭ������ ��� ��ü �����ϰ� �� ���ΰ�?

		strategy : interface�� ���� ��ü �����ϰ� ���ڴ� ��
		policy base design : template Arg�� ����ؼ� ��ü �����ϰ� ����.


							����							������
		Interface ��� : �����Լ�						����ð� ��ü ����
						 �ణ�� �������				edit.set_validator(&v1)
						 ������.						edit.set_validator(&v2)

		Template ��� :  �����Լ� �ƴ�.				����ð� ��ü �Ұ���
						 �ζ��� ġȯ�� ����			��ü ���� ��, �̹� ��å�� ����
						 ������.						vector<int, MallocAllocator<int>>


	Design Pattern : �پ��� ��ü���� ���� ��� ���� ������ ������ ������ (23��)
					 (template method, strategy, ...)
					 �ϴ�...GoF ���� �⺻���� ������ �ܿ�����.

	IDioms		   : �� ����� Ư¡�� ����� ������ ���
					 (policy base design, ...)
					 C++ IDioms, Java IDioms, C# Idioms

	���� "C++ IDioms" �˻� �� ù ��ũ ���� �Ʒ��� �������� c++ ���� ���� �� ����.
*/

template<typename T>
class MallocAllocator
{
public:
	inline T* allocate(std::size_t sz) {
		return static_cast<T*>(malloc(sizeof(T) * sz));
	}

	inline void deallocate(T* p, std::size_t sz) {
		free(p);
	}
};


// std::allocator<T> : C++ ǥ���� �����ϴ� �޸� �Ҵ��.
//					   new/delete �� �޸� �Ҵ�.
template<typename T, typename Alloc = std::allocator<T>>
class vector
{
	T* buff = nullptr;

	int size;
	// MallocAllocator<int> ax;			// ���� ����. ��ü �ȵ�.
	Alloc<int>* ax;				// template ���ڷ� ���޵� Ÿ�� ���
								// ��, template Arg�� ��å Ŭ���� ��ü
public:
	vector(int sz) : size(sz)
	{
		buff = ax.allocate(sz);		// liline �Լ� �̹Ƿ� "�ζ��� ġȯ"
									// �������� ����. ���� ����.
		//....
	}
	~vector()
	{
		ax.deallocate(buff, size);
		//....
	}
};

int main()
{
	vector<int, MallocAllocator<int>> v(4);

}
