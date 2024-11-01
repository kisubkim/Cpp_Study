#include <iostream>
#include <cstring>

class Person
{
	char* name;
	int   age;
public:
	Person(const char* s, int a) : age(a)
	{
		name = new char[strlen(s) + 1];
		strcpy_s(name, strlen(s) + 1, s);
	}
	~Person() { delete[] name; }

	Person(const Person& p) : age(p.age)
	{
		name = new char[strlen(p.name) + 1];
		strcpy_s(name, strlen(p.name) + 1, p.name);	
	}

	Person(Person&& p) : name(p.name), age(p.age)
	{
		p.name = nullptr;	
	}

};
Person foo()
{
	Person p("john", 20);
	return p;
}
int main()
{
	Person robert("robert", 30);

	Person p1 = robert;
	Person p2 = foo();

}
