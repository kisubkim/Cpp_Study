#include <iostream>

int main()
{
	// #1 : 이거 gotbolt.org 에서 확인해서 .exe의 세션구조, 메모리 올라갈 때 어떻게 올라가는지 잘 기억할 것.

	printf("hello\n");	// 이렇게 작성이 되면, hello 라는 문자열을 상수메모리에 만들고
						// mov edi, "상수메모리의 문자열주소"	<--- 이렇게 compiler가 만듬.
						// call printf

					
	// #2 문자열 배열 vs 문자열 포인터
	char sa[] = "abcd";
	//char* sp  = "abcd";		// C ok. C++ Error
	const char* sp = "abcd";		// C ok. C++ Error

	/*
		아래처럼 메모리 상에서 이루어져 있기 때문에 C++에서는 상수메모리를 사용하기 때문에
		앞쪼게 const 가 붙어야 build 가 됨.
		C 언어의 경우 컴파일은 되는데...runtime error 나서 죽음. (이건 결국 c언어 쪽이 잘못되었다는 이야기)

							["abcd"]  <--- 상수메모리에 존재.
								\
			---------------------\-----------
			stack                 \
				[a|b|c|d]        *sp
				   sa
	
	*/

	*sa = 'x';		// ok. stack 에 쓰기, R/W 가능
	//*sp = 'x';		// C 언어. runtime error


	// #3. flyweight
	// 문자열 배열 쓰면 그냥 stack 에 배열만들어지고 거기 한칸에 한 글자씩 들어감.
	/*
		sa1
		  [a|b|c|d]

		sa2
		  [a|b|c|d]
	*/
	char sa1[] = "abcd";
	char sa2[] = "abcd";

	// 아래는 상수메모리에 있는 "abcd" 문자열을 가리킴.
	/*
						  ["abcd"]  <--- 상수메모리에 존재.
						  /     \
			-------------/-------\-----------
			stack       /         \
				     *sp1        *sp2
	
	*/
	const char* sp1 = "abcd";
	const char* sp2 = "abcd";

	/*
		프로그램에서 읽기만 하는 문자열이 필요하면 문자열 배열이 아닌 문자열 포인터 사용

		C++
			std::string			: 문자열 소유 (동적할당해서 보관)
			std::string_view	: const char* 와 유사한 역활 (문자열 포인터)

		Rust
			str 타입		: const char*
			String		: std::string 과 유사
			
	*/
}