﻿// upcasting3.cpp
class Animal 
{
public: 
	int age;
};
class Cat : public Animal 
{
};
class Dog : public Animal
{
public:
	int color;
};

// upcasting 활용 #2. 동종을 처리하는 하수 만들기.

//void NewYear(Dog* pDog)		// 지금은 Dog 객체만 처리함.
void NewYear(Animal* p)			// 모든 동물을 처리하는 함수.
{
	++(p->age); 
	
}
int main()
{
	Animal a; NewYear(&a);
	Dog    d; NewYear(&d);
}











