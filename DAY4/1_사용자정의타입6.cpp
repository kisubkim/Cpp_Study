#include <iostream>
#include <unordered_set>
#include "show.h"

struct People
{
	std::string name;
	int  age;

	People(const std::string& n, int a) : name(n), age(a) {}
};

struct PeopleHash {
	int operator()(const People& p) const {
		std::hash<int> hi;
		std::hash<std::string> hs;

		return hs(p.name) + hi(p.age);
	}
};

struct PeopleEqual {
	bool operator()(const People& p1, const People& p2) const {
		return p1.name == p2.name && p1.age == p2.age;
	}
};


int main()
{
	//std::unordered_set<People> s;		// error
	//* 위 문장은 원래 아래 문장과 같음.
	//* std::unordered_set<People, std::hash<People>, std::equal_to<People>, std::allocator<People> s;
	// 2st : hash 방법
	// 3st : hash로 같은 위치를 찾게되었을 때, 옆으로 이동하면서 찾을 방법.

	std::unordered_set<People, PeopleHash, PeopleEqual> s;

	s.emplace("kim", 20); // s.insert( People("kim",20))
	s.emplace("lee", 25);
	s.emplace("park", 30);

	People peo("lee", 25);
	auto p = s.find( peo );

	std::cout << (*p).name << std::endl;
}

