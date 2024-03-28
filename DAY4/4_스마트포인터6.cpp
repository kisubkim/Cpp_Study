#include <iostream>
#include <memory>

void foo(void* p) { free(p); }

int main()
{
	// 삭제자 변경
	std::shared_ptr<int> sp1(new int);		// ok. sp1의 소멸자가 delete

	std::shared_ptr<int> sp2(static_cast<int*>(malloc(sizeof(int))));	// error, compile은 되긴함.
																		// 하지만 sp2 소멸자에서 free가 아닌 delete 진행.
	std::shared_ptr<int> sp3((int*)malloc(sizeof(int)), foo);	//^ ok. sp3 파괴시 소멸자에서 foo 호출.

	std::shared_ptr<int> sp4((int*)malloc(sizeof(int)), free);	//^ ok. sp3 파괴시 소멸자에서 free 호출.
	// shared_ptr 의 관리 객체 내부에는 여러 관리요소 (소멸자에서 호출할 함수 pointer라든지, 기타 등등) 가 있음.

	//--------------------------------------------------
	//^ array 할당.

	std::shared_ptr<int> sp5(new int[10]);		// bug, 잘못된 code. delete가 아닌 delete [] 필요
	//^ 위 문장을 안전하게 사용하려면, 삭제자 전달 필요
	std::shared_ptr<int> sp6(new int[10], [](int* p){ delete[] p; });

	//^ C++17부터는 아래처럼 해도 됨.
	std::shared_ptr<int[]> sp7(new int[10]);

	//^ new int[10] 처럼 array 가 필요하면 vector가 더 낳음. 권장.
	//^ new int 처럼 1개를 가지고 쓸 때, shared_ptr 권장.

	//^ std::make_shared() 사용하면 자원할당 방법 자체로 변경 불가능
	std::shared_ptr<int> sp9 = std::make_shared<int>(); 
}







