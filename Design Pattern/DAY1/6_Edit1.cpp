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
		data.clear();

		while (1) {
			char c = _getch();		// 한글자씩 키보드에서 직접 읽기

			if (c == 13) break;		// enter key

			if (isdigit(c)) // 숫자일 때만
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << '\n';
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


