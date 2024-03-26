#include <vector>

template<typename T, typename Ax = std::allocator<T>> 
class vector
{
	Ax ax;		// 메모리 할당기 (allocator)
				// vector의 모든 member function에서  메모리 할당이 필요하면
				// ax 객쳉의 member function을 사용해야함.
				// 여기는 default 로 new, delete 사용하도록 만들어 졌음.
public:
	void resize(int sz)
	{
		T* p = ax.allocate(sz);		// 할당.

		ax.deallocate(p, sz);		// 해지
	}
};

int main()
{
	std::vector<int> v(5);
	v.resize(10);
}


