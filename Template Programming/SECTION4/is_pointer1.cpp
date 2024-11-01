#include <iostream>

template<typename T> struct is_pointer
{
//	bool value = false;
	enum { value = false};
};

template<typename T> struct is_pointer<T*>
{
	enum { value = true};
};


template<typename T> 
void fn(const T& arg)
{
	if ( is_pointer<T>::value )
		std::cout << "pointer" << std::endl;
	else
		std::cout << "not pointer" << std::endl;
}

int main()
{
	int n = 0;
	fn(n);
	fn(&n);
}