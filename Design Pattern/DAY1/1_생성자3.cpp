// 1_생성자2.cpp
#include <string>
#include <iostream>

class Person
{
	std::string name;
	int age;
public:
	Person(const std::string& name, int age) : name(name), age(age) {}
	// 여기서 초기화 할 때, 그냥 () 사용보다는 {} 사용이 더 좋기는 함. 하지만 크게 차이..있기는 하지만 편하니까...ㅎ
};

// 1. Person에서 파생된 Student class 만들기
// 2. "int id" 멤버 추가
// 3. student 생성자 만들어서 id 초기화
// 4. main 에서 Student 객체 생성

struct Student : Person {
	int id;

	Student(const std::string name, int age, int id) : Person(name, age), id(id){}
	// 만약에 Student 생성자를 아래와 같이 만들었으면 error
	/*
		Student(int id) : id(id) {}
		기본적으로 개발자는 Student 상위 class인 Person에 default 생성자가 없다는 것을 확인해야하고,
		따라서 그에 합당하도록 생성자를 명시적으로 호출해야함.

		정말 좋은 class들은 보통 default constructor가 업는 경우가 많음. 잘 기억해 둘 것.
	*/
};


int main()
{
	//Person p1;	// 이렇게 객체를 만들수 있다는 것이 좋을까요 ? (초기화 되지 않은 객체)

	Person p1("kkk", 20);		// 가능하면 초기화된 객체를 사용할 수 있도록 해야함.
	Student aa("test", 22, 2134);
}


