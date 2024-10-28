#include <vector>
#include <iostream>

// 사용자 정의 메모리 할당기
// => 반드시 Template으로 만들어야 하는 것은 아님.
// => 다양한 타입의 메모리 할당이 필요하면 관례상 템플릿으로!!

// 요구되는 사항들이 좀더 있음. (메모리 관련해서.)
template<typename T>
class debug_alloc{

	public:
		T* allocate( std::size_t sz) {
			void* p = malloc(sizeof(T) * sz);
			printf("allocate : %p %d cnt\n", p, sz);
			return static_cast<T*>(p);
		}

		void deallocate(T* p, std::size_t sz) {
			printf("deallocate : %p %d cnt\n", p, sz);
			free(p);
		}

		// 위 2개 멤버함수 외에 아래 3개가 더 필요함.
		using value_type = T;

		debug_alloc() {} // default constructor
		template<typename U>
		debug_alloc(const debug_alloc<U>&) {} // template constructor

};

int main()
{
	//std::vector<int> v(5);		// 실제로는 std::vector<int, std::allocator<int>> v(5) 와 같은 의미.

	std::vector<int, debug_alloc<int>> v(5);
	v.resize(10);
}


