#include <iostream>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <list>

template<typename T>
void show(const T& c){
    for( auto& e:c){
        std::cout << e << ", ";
    }
    std::cout << std::endl;
}

template<typename InputItr>
void show(InputItr s, InputItr e){
    std::ostream_iterator<typename std::iterator_traits<InputItr>::value_type> p1(std::cout, ", ");
    std::copy(s, e, p1);
    std::cout << std::endl;
}


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

// 관례상으로 전역으로 빠짐. member 로 해도 상관은 없음.
// 현재 debug_alloc은 상태(member data)가 없어서 아래처럼 만들어도 괜춘함.
// ==, != 도 필요
		template<typename T>
		bool operator==(const debug_alloc<T>& a1, const debug_alloc<T>& a2){
			return true;
		}		

		template<typename T>
		bool operator!=(const debug_alloc<T>& a1, const debug_alloc<T>& a2){
			return false;
		}	
