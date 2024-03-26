#include <iostream>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <list>

int main()
{
	std::list<int> s = { 1, 2, 3, 4, 5 };

	std::ostream_iterator<int> p1(std::cout, " ");

	std::copy(s.begin(), s.end(), p1);

	std::cout << "a" << std::endl;

	*p1 = 10;

	std::cout << "b" << std::endl;


}
