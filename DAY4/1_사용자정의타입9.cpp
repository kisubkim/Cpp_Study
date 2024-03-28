#include <iostream>
#include <set>
#include "show.h"

struct People
{
	std::string name;
	int  age;

	People(const std::string& n, int a) : name(n), age(a) {}
};

template<>
struct std::less<People> {
	bool operator()(const People& p1, const People& p2) const {
		return p1.age < p2.age;
	}
};

// struct PeopleCompare {
// 	bool operator()(const People& p1, const People& p2) const {
// 		return p1.age < p2.age;
// 	}
// };

int main()
{
	std::set<People> s;

	s.emplace("kim", 20); // s.insert( People("kim",20))
	s.emplace("lee", 25);
	s.emplace("park", 30);

	People peo("lee", 25);
	auto p = s.find( peo );

	std::cout << (*p).name << std::endl;
}

