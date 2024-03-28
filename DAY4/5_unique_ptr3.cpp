#include <memory>
#include <iostream>

struct Freer{
	void operator()(void* p) {
		free(p);
		std::cout << "Freer operator()\n";
	}
};

int main()
{
	std::unique_ptr<int> up1(new int);		// ok
	std::unique_ptr<int> up2(new int[10]);	// bug. template 쪽도 [] 하던가..소멸자가 delete 호출됨. delete[] 되어야함.
											//& build 자체는 가능함.
	std::unique_ptr<int[]> up3(new int[10]);	// ok. c++14 부터	

	//^ 삭제자를 변경하려면 => template 2nd 인자로 함수객체 전달해야함.
	std::unique_ptr<int, Freer> up4(static_cast<int*>(malloc(sizeof(int))));


	//^ shared_ptr vs unique_ptr
	//? std::shared_ptr<int> sp(malloc할당, 삭제자 할당);
	//? std::unique_ptr<int, 삭제자> up(malloc할당);

	//^ shared_ptr : control block 이 있어서, 삭제자 거기 저장.
	//^ unique_ptr : 삭제자를 위한 저장 공간이 없어도 됨. (아래 참고)

	//^ shared_ptr : 삭제자를 변경해도 같은 타입 --> vector 에 넣을 수 있음.
	//^ unique_ptr : 삭제자를 변경하면 다른 타입 --> vector 에 넣을 수 없음.
}

//^ unique_ptr 소멸자 동작 원리.
template<typename T, typename Dx = std::default_delete<T>>
class unique_ptr{
	T* ptr; 		// 자원 pointer
	public:
	~unique_ptr() {
		Dx d;		// 삭제자 함수객체 생성
		d(ptr);		// 삭제
	}
};