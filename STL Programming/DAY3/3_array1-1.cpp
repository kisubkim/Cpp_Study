#include <vector>
#include <array>
#include "show.h"

void f1()
{
	int x[10];
}

void f2()
{
	std::vector<int> v(10);
}

void f3() 
{ 
	std::array<int, 10> a; 
}

void use_stdarray() {
	for (int i=0; i < 1000000; i++)
		f3();
}

void use_array() {
	for (int i=0; i < 1000000; i++)
		f1();
}

void use_vector() {
	for (int i=0; i< 1000000; i++)
		f2();
}

int main() {
	
	chronometry(use_array);
	chronometry(use_vector);
	chronometry(use_stdarray);
	
}
