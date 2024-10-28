#include <iostream>

int main()
{
	// C++, RUST, C#, Java ���� ���ڿ� Ŭ������ �Ϻ��� �����Ϸ���
	// �Ʒ� ���̸� ��Ȯ�� �˾ƾ� �մϴ�.
	// 
	// #1. ���ڿ� �迭 vs ���ڿ� ������
	char sa[] = "abcd";
	//	char* sp  = "abcd"; // stack ���� �����͸�, 
							// ���� ���ڿ��� ��� �޸�(.rdata, .rodata)
							// C ��� : ok. ������ �Ʒ� *sp='x' �� ��Ÿ�ӿ���
							// C++��� : error. 
	const char* sp = "abcd"; // C++ �� �̷��Ը� ����

	*sa = 'x'; // ok
	//	*sp = 'x'; // char* ��� runtime-error. ����޸𸮸� �����Ϸ��� �ϰ� �ִ�.
					// const char* ��� compile -time error


		// #2. Flyweight

	char sa1[] = "abcd";
	char sa2[] = "abcd";

	const char* sp1 = "abcd"; // -> ���ڿ������ʹ� ����� ����Ű�Ƿ�, ���浵 �Ұ��ϰ�, �׷��� flyweight�� �ȴ�.
	const char* sp2 = "abcd"; // �б� �������� ���ڿ��� �ٷ궧��, ���ڿ� �����ͷ��ϸ� �޸𸮰� ����� ����ȴ�.

	// �Ʒ� ��� ������ ������. ���� �ּ� ? �ٸ� �ּ� ?
	printf("%p, %p\n", sa1, sa2);
	printf("%p, %p\n", sp1, sp2);
}