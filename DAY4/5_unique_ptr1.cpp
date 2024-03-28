#include <iostream>

template<typename T>
class Ptr
{
	T* obj;
public:
	// 아래에서 explicit을 붙이면 = 사용 불가능.
	//inline Ptr(T* p = 0) : obj(p) {}
	inline explicit Ptr(T* p = 0) : obj(p) {}
	inline T* operator->() { return obj; }
	inline T& operator*() { return *obj; }
	~Ptr() { delete obj; }

	//^ 함수 삭제 문법
	//^  => compiler가 자동으로 만드는 함수를 만들지 못하게 할 때 사용.
	Ptr(const Ptr& other) = delete;

	//^ move 생성자
	//? noexcept 내용 한번 확인해 볼 것.
	inline Ptr(Ptr&& other) noexcept : obj(other.obj) {
		other.obj = nullptr;		// 인자로 전달된 객체의 자원포인터는 reset
	}
};

int main()
{
	//Ptr<int> p1 = new int;		// explicit 때문에 사용 막힘.
	Ptr<int> p1(new int);
	*p1 = 100;
	std::cout << *p1 << std::endl;

	//Ptr<int> p2 = p1; // 이 코드 때문에 runtime error 발생
					  // 함수 삭제 문법 활용해서 compile 시에 error 나오게 해서 build 막기.

	Ptr<int> p3 = std::move(p1);		//^ 요거는 정상동작을 해야함. 이를 위해서 move 생성자 작성 필요.
}


