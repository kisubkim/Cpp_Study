// 3_함수객체4 -  137 page 제일 윗부분내용
       int Add1(int a, int b) { return a + b; }
inline int Add2(int a, int b) { return a + b; }

int main()
{
	int n1 = Add1(1, 2); 	// function call
							// 1. 인자인 1, 2를 약속된 장소(레지스터)에 넎고
							// 2. Add1 함수 위치로 이동 (call Add1)
	int n2 = Add2(1, 2); 	// Add2의 기계어 code를 이 위치에 치환
							// mov eax, 2
							// add eax, 1
							// mov n2, eax

	
	int(*f)(int, int) = &Add2;		// 아무리 인라인 함수라도 함수 포인터에 담아서 사용하면 치환되지 않음.
	//if (사용자입력 == 1) f = &Add2;

	f(1, 2); // ?

	//^ 1. 인라인 치환은 "컴파일 시간에 동작"하는 문법.
	//^ 2. 인라인 함수라도 "함수포인터에 담아서 호출" 하면 인라인 치환될 수 없음.
	//^ ==> godbolt 에서 확인해보면 암.
}

// godbolt.org 사이트 접속
// => 다양한 언어의 컴파일 결과를 기계어(어셈블리)로 볼 수 있는 사이트

