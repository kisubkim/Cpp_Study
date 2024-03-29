#include <stdio.h>

int x = 100;

int main(){
	char* s3 = "ABCD";		// C 에서는 error 가 아님.
	*s3 = 'X';		// C 언어 실행시 에러. 죽음.
	//& 하지만 c++에서는 const 가 없어서 compile error

	const char* s1 = "ABCD";
	const char* s2 = "abcd";

	printf("ABCD");
}
