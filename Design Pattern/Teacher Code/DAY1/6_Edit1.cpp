// 33 page ~ 
#include <iostream>
#include <string>
#include <conio.h>

class Edit
{
	std::string data;
public:
	std::string get_data()
	{
		std::cin >> data;
		return data;
	}
};

int main()
{
	Edit e;			// 실제 GUI 모양으로 Edit box 가 나타난다고 가정. (ex>실행창)
	while (1)
	{
		std::cout << e.get_data() << std::endl;
	}
}


