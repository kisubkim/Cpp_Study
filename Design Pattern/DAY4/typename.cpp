

struct Test {
	using dword = int;		// typedef int dword;
	inline static int value = 10;
};
int p1 = 0;

template<typename T> void foo(T a) {
	/*
		아래 2줄에서 *의 의미를 생각해 보자.

		"글래스이름::이름" 에서 "이름"은 2가지 의미가 가능.
			1. 값
			2. 타입
		=> 이름의 의미에 따라 연산자 해석 방식이 변경됨.
		=> 컴파일러는 Test 선언을 통해서 의미를 해석할 수 있음.
	*/
	
	//Test::value* p1;		// 여기서는 곱하기 의미.
	//Test::dword* p2;		// 여기서는 포인터 의미. 포인터 연산자. int* p2
	
	// dependent name (의존 이름)
	// => Template Arg T 에 의존해서 꺼내는 이름 "T::이름"
	// => 위쪽은 Test 라는 class name이 있어서 compiler가 명확히 알 수 있지만,
	//    아래는 T를 알 수 없음으로 compiler가 알 수가 없음. 그래서 "T::이름" 을 무조건 값으로 해석하기로 약속함.
	T::value* p1;		// "값인데 * p1" 이네, p1이 전역 본수. ok
	//T::dword* p2;		// 곱하기로 해석해야 하는데, p2가 없네? ---> Error
	typename T::dword* p2;	// dword 를 값이 아닌 타입으로 해석해 달라.
							// 곱하기가 아닌 포인터 변수의 선언이므로 p2를 이 순간 만드는 것. OK.
	
						
}

int main() {

}

/*
	
*/