#include <iostream>
#include "show.h"

#include <set> 

int main()
{
	std::set<int> s;

	s.insert(20);
	s.insert(30);
	s.insert(15);
	s.insert(5);
	s.insert(40);

	// #1. 중복 허용 안함, 반환값
	std::pair<std::set<int>::iterator, bool> ret = s.insert(15);		// 실패. 
	//* set의 값을 받을 때는 pair로 받아야함.
	// c++11 이후로는 걍 auto 쓰면 편함.
	auto ret2 = s.insert(5);
	if (ret2.second == false){
		std::cout << "fail. element already existed.\n";
	}

	// #2. 요소 삽입은 insert(또는 emplace) 만 가능
	//s.push_back(50); //? tree..즉, set은 insert, emplace만 가능함. 왜? root 부터 거쳐야 하니까!!

	// #3. 반복자는 읽기만 가능
	auto p = s.begin();
	//? *p = 20;		// error. 값이 변경되면 Tree 망가짐.
	

	// #4. 검색
	// error는 아닌데 엄청 느림. 왜? Binary Search 써야지. //^ Tree는 'find - 선형검색' 으로 찾으면 느림
	auto ret1 = std::find(s.begin(), s.end(), 30);		// 일반함수는 Linear Search
	auto ret3 = s.find(20);		// member function에 제공된 걸로 사용. Binary Search



	// #5. 값이 있는지 조사
	//if (ret3 == s.end())		// 요게 기본적인 내용.

	// c++20부터 아래 함수 제공
	//if (s.contains(30))
	
}







