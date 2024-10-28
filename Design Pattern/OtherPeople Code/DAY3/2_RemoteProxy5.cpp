#include "ICalc.h"
#include <iostream>
int main()
{
	ICalc* calc = load_proxy();
	int n1 = calc->Add(10, 20);
	int n2 = calc->Sub(10, 20);

	// dll delete또한 header가 지원해야함.

	std::cout << n1 << ", " << n2 << std::endl;

}


