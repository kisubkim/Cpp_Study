#include "chronometry.h"
#include <vector>
#include <list>
#include <algorithm>

// compiler 옵션에서 최적화를 꼭 써야 차이가 남.
// vector 가 list 보다 10배 속도 차이남.

constexpr std::size_t size = 10'000'000;

std::vector<int> v;
std::list<int> s;


void use_list()
{
	for( int i = 0; i < size; i++ )
	{
		s.push_back(0);
	}
}

void use_vector()
{
	for( int i = 0; i < size; i++ )
	{
		v.push_back(0);
	}
}

int main()
{	
	chronometry(use_list);
	chronometry(use_vector);
}