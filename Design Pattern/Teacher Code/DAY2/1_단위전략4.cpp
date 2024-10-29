#include <iostream>
#include <cstdlib> 

// ��� #3. ��������(Policy Base Design)
// => ��åŬ������ "�������̽�"�� ����ؼ� ��ü �ϴ°��� �ƴ϶�
// => template ���ڷ� ��ü�ϴ� ���


template<typename T> class MallocAllocator 
{
public:
	inline T* allocate(std::size_t sz) 
	{
		return static_cast<T*>(malloc(sizeof(T) * sz));
	}
	inline void deallocate(T* p, std::size_t sz)
	{
		free(p);
	}
};


// std::allocator<T> : C++ ǥ���� �����ϴ� �޸� �Ҵ��
//						new/delete �� �޸� �Ҵ�.
template<typename T, typename Alloc = std::allocator<T> >
class vector
{
	T* buff = nullptr;
	int size;

//	MallocAllocator<int> ax; // ���� ����. ��ü �ȵ�
	Alloc ax;				 // ���ø� ���ڷ� ���޵� Ÿ�� ���
							 // ��, ���ø� ���ڷ� ��å Ŭ���� ��ü
public:
	vector(int sz) : size(sz)
	{
		buff = ax.allocate(sz); // �ζ��� �Լ� �̹Ƿ� "�ζ��� ġȯ"
								// �������� ����. ���� ������.
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

//	vector<int, MallocAllocator<int>> v(4);

	vector<int> v(4);


}



// strategy vs policy base design
// => ��� Ŭ������ ����ϴ� � ��å�� "�ٸ� Ŭ������ �и�" ���ڴ� ��

// => �׷���, ��å Ŭ������ ��� ��ü �����ϰ� �Ұ��ΰ� ?
// 
// strategy           : �������̽��� ���� ��ü �����ϰ� ���ڴ� ��
// policy base design : template ���ڸ� ����ؼ� ��ü �����ϰ� ����.

//						����				������
// �������̽� ��� :		�����Լ�			����ð� ��ü ����
//						�ణ�� �������	edit.set_validator(&v1)
//						������.			edit.set_validator(&v2)
// 
// template ����  :		�����Լ��ƴϰ�		����ð� ��ü �ȵ�.
//						�ζ��� ġȯ�� ����	��ü ������ �̹� ��å�� ����
//						������.				����� ��ü�� �ȵ�.
//											vector<int, MallocAllocator<int>> 

// ������ ���� : �پ��� ��ü���� ���� ��� ���� ������ ������ ������ ( 23�� )
//				(template method, strategy ... )
// 
// IDioms     : �� ����� Ư¡�� ����� ������ ���
//				(policy base design ....)
//			    C++ IDioms, Java IDioms, C# IDioms

// ���� "C++ IDioms" �˻�