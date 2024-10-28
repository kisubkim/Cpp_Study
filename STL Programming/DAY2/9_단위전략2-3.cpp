#include <vector>
#include <iostream>

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

		using value_type = T;

		debug_alloc() {}
		template<typename U>
		debug_alloc(const debug_alloc<U>&) {}

};

//& 보니까 최대 할당된 size를 어딘가에서 관리하나봄. 요게 capacity 임
// 줄었다가 다시 올라왔을 때도 기존에 할당 받았던거 그대로 사용.
int main()
{
	std::vector<int, debug_alloc<int>> v;

	std::cout << "---------------------------\n";
	v.resize(5);		// 5개 할당
	std::cout << "---------------------------\n";
	v.resize(10);		// 1. 10개 할당
						// 2. 5개 => 10개에 복사
						// 3. 5개 해지
	std::cout << "---------------------------\n";
	v.resize(7);		// 이거는 그냥 10개짜리 씀.
	std::cout << "---------------------------\n";
	v.resize(9);		// 이거는 그냥 10개짜리 씀.
	std::cout << "---------------------------\n";
	v.clear();		//& 이거 내용을 지우지만 메모리는 지우지 않음.
	std::cout << "---------------------------\n";
	// 나갈 때 10개짜리 해지.
}


