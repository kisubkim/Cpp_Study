#include <map>  
#include "show.h"

// map : pair 를 저장하는 set,   key 값으로 value 를 저장
//^ tree는 tree 인데, 내부에 pair가 들어감.
//^ first - key 로 비교 판단함. data는 second
//& set 에서 들어가는 data가 pair 로 변경되었다고 인식하면 됨.

int main()
{
	std::map<std::string, std::string> m = { {"mon", "월요일"}, {"tue", "화요일"}};

	// #1. 요소 넣기
	// 1. pair 만들어서 넣기
	// std::pair<std::string, std::string> p("wed", "수요일");
	// m.insert(p);

	// 2. make_pair
	//m.insert(std::make_pair("wed", "수요일"));

	// 3. emplace
	//m.emplace("wed", "수요일");		// 자세한 내용은 '사용자 정의 타입' 주제에서.

	// 4. [] 연산자 사용
	//------------------------
	m["wed"] = "수요일";
	
	// #2. 반복자에 대해서
	// iterator : element를 가리키는 pointer
	// element of map : std::pair
	// iterator of map : std::pair*
	auto p = m.find("wed"); // find(키값)

	// p를 사용해서 "wed : 수요일" 이라고 출력해보세요
	std::cout << p->first << " : " << p->second << std::endl;

	// #3. for 와 map
	//for( auto e:m) {		// e는 std::pair. //^ 이거는 메모리 공간에 할당해서 복사한 것. (object instance 니까.)
	for( const auto& e:m) {	// e는 //^ std::pair* 가 만들어 져서 기존 map의 위치를 가리킴.
		std::string key = e.first;
		std::string value = e.second;
	}

	// 하단 ref 내용 참고.
	for( const auto& [key, value]:m) {	//& key에다가 first, value 에다가 second 값을 그대로 넣은 것.
		//key = ~~
	}

	// #4. [] 연산자
	std::cout << m["sun"] << std::endl; 	//* map은 key 값이 없으면 "sun", "" 항목 추가
											//* key 있으면 sun에 matching 되는 second 반환

	//& key exist check 할 때, 절대 아래처럼 하면 X
	//if (m["sun"] == "")  // pair 생성해서 입력한 것임.

	auto ret2 = m.find("sun");
	if (ret2 == m.end()) {}

	// C++20부터 contains 지원
	if (m.contains("sun")) {}		//* 내부 원리는 위의 find 사용하는 부분과 동일.
	// auto 만 [] 사용해서 자동으로 변수 선언 및 입력이 가능.
	// ref.
	// Point pt;
	// int a = pt.x;
	// int b = pt.y;
	// // 위를 한줄로 끝낼려면?
	// // c++ 17부터 지원 //& structure binding
	// auto[a, b] = pt;

	// auto[error, value] = foo();
	
}

std::tuple<int, int> foo() {
	return std::make_tuple(10, 20);
}




