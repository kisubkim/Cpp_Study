// 42 page ~ 
#include <iostream>
#include <cstdlib>
/*
	방법
		1. template method pattern 사용
			=> 변하는 것 (메모미 할당 / 해지 방법)을 가상함수로 분리하자는 것

	단점
		=> 메모리 할당/해지 알고리즘을 "vector의 파생 클래스(MallocVector)"가 소유하게 됨.
		=> list, set, map 등에도 메모리 할당 알고리즘을 변경하려면 동일하게 파생 클래스를
		   만들어서 다시 할당 알고리즘을 작성해야함.

		   Template Method는 구현한 알고리즘을 상속받는 특정 class(파생클래스)가 소유하게 됨.
*/

template<typename T>
class vector
{
	T* buff = nullptr;
	int size;
public:
	// #1. 메모리 할당/해지를 책임지는 가상함수 도입
	virtual T* allocate(std::size_t sz) { return new T[sz]; }
	virtual void deallocate(T* p, std::size_t sz) { delete[] p; }

	// #2. vector의 모든 멤버 함수에서 메모리 할당 / 해지가 필요하면 allocate/deallocate 가상함수 사용
	vector(int sz) : size(sz)
	{
		buff = allocate(sz);
		//....
	}
	~vector()
	{
		deallocate(buff, size);
		//....
	}
};

// 핵심 : 메모리 할당/해지를 변경하려면 파생 클래스를 만들면 됨.
template<typename T> class MallocVector : public vector<T>
{
public:
	T* allocate(std::size_t sz) override {
		return static_cast<T*>(malloc(sizeof(T) * sz));
	}

	void deallocate(T* p, std::size_t sz) override {
		free(p);
	}
};


int main()
{
	//vector<int> v(4);
	MallocVector<int> v(4);
}
