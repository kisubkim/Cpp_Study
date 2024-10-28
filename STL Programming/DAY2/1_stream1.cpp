#include <iostream>
#include <iterator>
#include <list>
#include <fstream>

int main()
{
	int n = 10;

	std::cout << n << std::endl;

	// 출력 stream iterator
	std::ostream_iterator<int> p(std::cout, " ");
	// cout을 사용해서 반복해서 출력하는 반복자.

	*p = 10;		// std::cout << 10 << " "
	*p = 20;		// std::cout << 10 << " " << 20
	*p = 40;
	// 이거 pointer 에다가 계속 추가하고 나면, " " 씩 띄워서 입력한 값들이 한번에 들어가서 보임.

	std::ofstream fout("a.txt");		// 출력 파일 객체
	std::ostream_iterator<int> p2(fout, " ");

	*p2 = 20;
	*p2 = 30;

}
