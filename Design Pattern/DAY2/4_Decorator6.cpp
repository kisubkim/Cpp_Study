#define _CRT_SECURE_NO_WARNINGS		// fopen() 등 오래된 함수 사용해도 error 나지 않게 하는 define
#include <iostream>


/*
	모든 stream 의 함수가 동일함을 보장하기 위해 Interface design

*/

struct Stream {
	virtual void write(const std::string&) = 0;
	virtual ~Stream() {}

	// 이 외에도 read, flush, is_open, close 등의 함수 이름을 약속
};

class FileStream : public Stream
{
	FILE* file;
public:
	FileStream(const char* s, const char* mode = "wt")
	{
		file = fopen(s, mode);
	}
	~FileStream() { fclose(file); }

	void write(const std::string& s)
	{
		printf("%s 쓰기\n", s.c_str());
	}
};



int main()
{
	FileStream fs("a.txt");
	fs.write("hello");

	// 아래와 같은 class도 있다고 가정해보자.

	PipeStream ps("my named pipe");
	ps.write("hello");

	NetworkStream ns("100.100.100.100", 4000);
	ns.write("hello");
}
