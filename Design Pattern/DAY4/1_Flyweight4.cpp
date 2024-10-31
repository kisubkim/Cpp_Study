#include <iostream>

int main()
{
	// #1 : �̰� gotbolt.org ���� Ȯ���ؼ� .exe�� ���Ǳ���, �޸� �ö� �� ��� �ö󰡴��� �� ����� ��.

	printf("hello\n");	// �̷��� �ۼ��� �Ǹ�, hello ��� ���ڿ��� ����޸𸮿� �����
						// mov edi, "����޸��� ���ڿ��ּ�"	<--- �̷��� compiler�� ����.
						// call printf

					
	// #2 ���ڿ� �迭 vs ���ڿ� ������
	char sa[] = "abcd";
	//char* sp  = "abcd";		// C ok. C++ Error
	const char* sp = "abcd";		// C ok. C++ Error

	/*
		�Ʒ�ó�� �޸� �󿡼� �̷���� �ֱ� ������ C++������ ����޸𸮸� ����ϱ� ������
		���ɰ� const �� �پ�� build �� ��.
		C ����� ��� �������� �Ǵµ�...runtime error ���� ����. (�̰� �ᱹ c��� ���� �߸��Ǿ��ٴ� �̾߱�)

							["abcd"]  <--- ����޸𸮿� ����.
								\
			---------------------\-----------
			stack                 \
				[a|b|c|d]        *sp
				   sa
	
	*/

	*sa = 'x';		// ok. stack �� ����, R/W ����
	//*sp = 'x';		// C ���. runtime error


	// #3. flyweight
	// ���ڿ� �迭 ���� �׳� stack �� �迭��������� �ű� ��ĭ�� �� ���ھ� ��.
	/*
		sa1
		  [a|b|c|d]

		sa2
		  [a|b|c|d]
	*/
	char sa1[] = "abcd";
	char sa2[] = "abcd";

	// �Ʒ��� ����޸𸮿� �ִ� "abcd" ���ڿ��� ����Ŵ.
	/*
						  ["abcd"]  <--- ����޸𸮿� ����.
						  /     \
			-------------/-------\-----------
			stack       /         \
				     *sp1        *sp2
	
	*/
	const char* sp1 = "abcd";
	const char* sp2 = "abcd";

	/*
		���α׷����� �б⸸ �ϴ� ���ڿ��� �ʿ��ϸ� ���ڿ� �迭�� �ƴ� ���ڿ� ������ ���

		C++
			std::string			: ���ڿ� ���� (�����Ҵ��ؼ� ����)
			std::string_view	: const char* �� ������ ��Ȱ (���ڿ� ������)

		Rust
			str Ÿ��		: const char*
			String		: std::string �� ����
			
	*/
}