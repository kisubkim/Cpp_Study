#include <iostream>
#include <vector>

struct Point3D
{
	int x = 1;
	int y = 2;
	int z = 3;

	int* begin() { return &x; }
	int* end() { return &z + 1; }
};

int main()
{
	Point3D p;

	for (auto e : p)
	{
		std::cout << e << ", ";
	}
}
// 컴파일 해서 에러메세지 확인하세요