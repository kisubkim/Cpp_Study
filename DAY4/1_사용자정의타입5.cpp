#include <iostream>
#include <set>
#include "show.h"

struct People
{
	std::string name;
	int  age;

	People(const std::string& n, int a) : name(n), age(a) {}
};

// set 에 2st template parameter 로 전달되려면
// People object 2개를 비교할 수 있는 함수 객체이어야함.

struct PeopleCompare {
	bool operator()(const People& p1, const People& p2) const {
		return p1.age < p2.age;
	}
};

int main()
{
	//^ 1. std::set에 보관되는 타입은 반드시 크기 비교가 가능해야함.
	//std::set<People> s;		// error
	// std::set<People, std::less<People>, std::allocator<People>> s; 이 코드로 바뀜. default 값
	// => std::less는 "<" 로 비교를 하고 있음.
	//* 해결책은 "비교함수객체" 를 반영

	std::set<People, PeopleCompare> s;		// PeopleCompare는 People 2개를 받아서 비교를 하면 됨.

	s.emplace("kim", 20); // s.insert( People("kim",20))
	s.emplace("lee", 25);
	s.emplace("park", 30);

	People peo("lee", 25);
	auto p = s.find( peo );

	std::cout << (*p).name << std::endl;
}

