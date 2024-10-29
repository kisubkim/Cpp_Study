// 42 page ~ 

#include <iostream>
#include <cstdlib>
/*
	방법
		3. Policy Base Design (단위 전략)
			=> 정책클래스를 "Interface"를 사용해서 교체 하는 것이 아니라 template 인자로 교체하는 기술
*/


/*
	strategy VS policy base design
		=> 모두 클래스가 사용하는 어떤 정책을 "다른 클래스로 분리" 하자는 것

		=> 그런데, 정책 클래스를 어떻게 교체 가능하게 할 것인가?

		strategy : interface를 만들어서 교체 가능하게 하자는 것
		policy base design : template Arg를 사용해서 교체 가능하게 하자.


							성능							유연성
		Interface 기반 : 가상함수						실행시간 교체 가능
						 약간의 오버헤드				edit.set_validator(&v1)
						 느리다.						edit.set_validator(&v2)

		Template 기반 :  가상함수 아님.				실행시간 교체 불가능
						 인라인 치환도 가능			객체 생성 시, 이미 정책이 결정
						 빠르다.						vector<int, MallocAllocator<int>>


	Design Pattern : 다양한 객체지향 언어로 모두 구현 가능한 범용적 디자인 (23개)
					 (template method, strategy, ...)
					 일단...GoF 꺼를 기본으로 무조건 외워야함.

	IDioms		   : 각 언어의 특징을 고려한 디자인 기술
					 (policy base design, ...)
					 C++ IDioms, Java IDioms, C# Idioms

	구글 "C++ IDioms" 검색 후 첫 링크 들어가서 아래로 내려가면 c++ 관련 내용 다 나옴.
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


// std::allocator<T> : C++ 표준이 제공하는 메모리 할당기.
//					   new/delete 로 메모리 할당.
template<typename T, typename Alloc = std::allocator<T>>
class vector
{
	T* buff = nullptr;

	int size;
	// MallocAllocator<int> ax;			// 강한 결함. 교체 안됨.
	Alloc<int>* ax;				// template 인자로 전달된 타입 사용
								// 즉, template Arg로 정책 클래스 교체
public:
	vector(int sz) : size(sz)
	{
		buff = ax.allocate(sz);		// liline 함수 이므로 "인라인 치환"
									// 성능저하 없음. 아주 빠름.
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
