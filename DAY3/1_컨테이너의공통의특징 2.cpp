// STL 컨테이너의 특징
#include <vector>
#include <iostream>
#include "show.h"

// 일반적 STL container 내부, using 사용 typedefine
template<typename T>
class Stack
{

};

class People {};

int main()
{
	Stack<People> s;
	s.push(People());
	
	try {
		People p = s.pop();		// 이 한줄을 생각 => 제거, 반환 동시에 한다면
								// 1. stack에서 제거
								// 2. 반환
								// 3. "p = 반환값" 에서 복사생성자 호출
								//? 그런데 3번에서 error 발생하면?
								//* => 이때 s 에서 pop 되기 전의 값을 가져야 함!!
								//& 그래서 순서는 받고 나서 제거! ==> 그래서 제거, 반환 동시가 없음.
	}
	catch(...) {		//& exeption 잡았어도 이미 손실은 발생

	}

	//^ exeption safety (예외 안전성)의 강력 보장
	// => 예외가 발생해도 잡아서 처리했다면 객체의 상태는 예외 이전 상태를 보장한다는 이론.
	
}
