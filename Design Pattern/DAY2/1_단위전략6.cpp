#include <iostream>
#include <vector>

/*
	사용자 정의 메모리 할당기 (STL containter 용)
		1, 반드시 template 일 필요는 없지만 다양한 타입에 사용하기 위해 대부분 template

		2. 반드시 약속된 함수를 만들어야 함. (약속된 함수는 표준문서에 적효 있음)
			=> 함수 이름과 모양은 "Interface"로 만들지 않고, 문서화(표준문서)로 약속

*/
// 

template<typename T>
struct debug_alloc {
	// mallocallocator 에서 2개 복사
	T* allocate(std::size_t sz) {
		T* p = static_cast<T*>(malloc(sizeof(T) * sz));
		printf("allocate %p, %zu cnts\n", p, sz);
		return p;
	}

	void deallocate(T* p, std::size_t sz) {
		printf("deallocate %p, %zu cnts\n", p, sz);
		free(p);
	}

	// 위 2개위에 아래 3개가 필요 (관례적인 코드이므로, 그냥 복사해서 사용하면 됨)
	using value_type = T;
	debug_alloc() {}
	template<typename U> debug_alloc(const debug_alloc<U>&) {}
};

int main()
{
	std::vector<int, debug_alloc<int>> v;

	std::cout << "-----------------" << std::endl;

	v.resize(4);		// memory 할다이로 4개 할당.

	std::cout << "-----------------" << std::endl;

	v.resize(8);		// 1. memory 할다이로 8개 할당
						// 2. 4개 내용 -> 8개로 복사
						// 3. memory 할당기로 4개 제거

	std::cout << "-----------------" << std::endl;
}
