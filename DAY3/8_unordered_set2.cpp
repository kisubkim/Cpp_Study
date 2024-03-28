#include <iostream>
#include <set>
#include <unordered_set>
#include "show.h"

// set, unordered_set의 사용법은 거의 동일
// 하지만 내부 동작 방식은 완전 다름

// set은 정렬유지.
// unordered_set 정렬 유지 X
int main()
{
	//std::set<int> s;
	std::unordered_set<int> s;
	s.reserve(100);

	s.insert(10);
	s.insert(35);
	s.insert(20);
	s.insert(25);	// set 		 	 : root 부터 비교해서 좌, 우로 이동
					// unordered_set : hash function에 보내서, hash value 얻은 후 bucket에 보관.

	auto p = s.find(20); 	// set : root 부터 검색
							// unordered_set : hash function으로 검색.

	std::cout << *p << std::endl;

	show(s);

	std::cout << "bucket count : " << s.bucket_count() << std::endl;
	for(int i=0; i < s.bucket_count(); i++) {
		std::cout << "bucket size : " << s.bucket_size(i) << std::endl;
	}
}

