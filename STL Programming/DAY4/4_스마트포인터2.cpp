#include <iostream>

// Ptr 복사해오세요

// 1. template 으로 만들기
// 2. 얕은 복사 해결하기 ==? 관례적으로 참조계수 사용
template<typename T>
class Ptr
{
	T* obj;
    int* ref;
public:
	Ptr(T* p = 0) : obj(p) {
        ref = new int;
        *ref = 1;
    }

    Ptr(const Ptr& other) : obj(other.obj) ref(other.ref) 
    {
        ++(*ref);
    }

	~Ptr() { 
        if (--(*ref) == 0)
        {
            delete obj;
            delete ref;
        }
         
    }

	T* operator->() { return obj; }
	T& operator*() { return *obj; }
};

int main()
{
    Ptr<int> p1 = new int;
    *p1 = 10;

    Ptr<int> p2 = p1;       //? 이때 현상을 생각해 보세요 --> 얖은 복사가 일어남!!

    //& 그래서 smart pointer 는 참조로 잘 사용
}

//& 나중에 만든게 먼져 죽음. 맨 마지막에 new 한넘이 맨 먼저 delete 됨. (stack)


