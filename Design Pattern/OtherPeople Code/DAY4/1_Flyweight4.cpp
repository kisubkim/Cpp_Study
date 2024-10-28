#include <iostream>

int main()
{
	// C++, RUST, C#, Java 등의 문자열 클래스를 완벽히 이해하려면
	// 아래 차이를 정확히 알아야 합니다.
	// 
	// #1. 문자열 배열 vs 문자열 포인터
	char sa[] = "abcd";
	//	char* sp  = "abcd"; // stack 에는 포인터만, 
							// 실제 문자열은 상수 메모리(.rdata, .rodata)
							// C 언어 : ok. 하지만 아래 *sp='x' 가 런타임에러
							// C++언어 : error. 
	const char* sp = "abcd"; // C++ 은 이렇게만 가능

	*sa = 'x'; // ok
	//	*sp = 'x'; // char* 라면 runtime-error. 상수메모리를 변경하려고 하고 있다.
					// const char* 라면 compile -time error


		// #2. Flyweight

	char sa1[] = "abcd";
	char sa2[] = "abcd";

	const char* sp1 = "abcd"; // -> 문자열포인터는 상수를 가리키므로, 변경도 불가하고, 그래서 flyweight가 된다.
	const char* sp2 = "abcd"; // 읽기 전용으로 문자열을 다룰때는, 문자열 포인터로하면 메모리가 상당히 절약된다.

	// 아래 결과 예측해 보세요. 같은 주소 ? 다른 주소 ?
	printf("%p, %p\n", sa1, sa2);
	printf("%p, %p\n", sp1, sp2);
}