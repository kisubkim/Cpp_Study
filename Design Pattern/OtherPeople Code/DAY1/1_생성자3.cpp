// 1_생성자2.cpp
#include <string>
#include <iostream>

class Person
{
	std::string name;
	int age;
public:
	Person(std::string name, int age): name(name), age(age) {}
	int getAge() {
		return age;
	}
};

class Student : Person
{
	int id;
public:
	Student(std::string name, int age, int id): Person(name, age), id(id) {}
	int getAge() {
		return Person::getAge();
	}
	// same
};

int main()
{
	Student s1("kin", 35, 15);	// 이렇게 객체를 만들수 있다는 것이 좋을까요 ? (초기화 되지 않은 객체) - 버그의 원인이 된대요, 생성자가 반드시 필요해요
	std::cout << s1.getAge();
}


