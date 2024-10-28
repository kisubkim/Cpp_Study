#include <iostream>
#include <unordered_set>
#include "show.h"

//* c++ standard 의 std::hash template 을 사용자가 만든 타입에 대해서 
//* 특수화 version을 제공하는 기법도 가능.

struct People
{
	std::string name;
	int  age;

	People(const std::string& n, int a) : name(n), age(a) {}
};

//& template specialization 사용해서 user type에 대한 hash function, equal_to 구현해서 추가.
template<>
struct std::hash<People> {
	int operator() (const People& p) const {
		std::hash<int> hi;
		std::hash<std::string> hs;
		return hs(p.name) + hi(p.age);		
	}
};

template<>
struct std::equal_to<People> {
	bool operator()(const People& p1, const People& p2) const {
		return p1.name == p2.name && p1.age == p1.age;
	}
};

// struct PeopleHash {
// 	int operator()(const People& p) const {
// 		std::hash<int> hi;
// 		std::hash<std::string> hs;

// 		return hs(p.name) + hi(p.age);
// 	}
// };

// struct PeopleEqual {
// 	bool operator()(const People& p1, const People& p2) const {
// 		return p1.name == p2.name && p1.age == p2.age;
// 	}
// };


int main()
{
	std::unordered_set<People> s;
	//std::unordered_set<People, PeopleHash, PeopleEqual> s;

	s.emplace("kim", 20); // s.insert( People("kim",20))
	s.emplace("lee", 25);
	s.emplace("park", 30);

	People peo("lee", 25);
	auto p = s.find( peo );

	std::cout << (*p).name << std::endl;
}

