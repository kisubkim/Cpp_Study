#define _CRT_SECURE_NO_WARNINGS		// fopen() �� ������ �Լ� ����ص� error ���� �ʰ� �ϴ� define
#include <iostream>


/*
	��� stream �� �Լ��� �������� �����ϱ� ���� Interface design

*/

struct Stream {
	virtual void write(const std::string&) = 0;
	virtual ~Stream() {}

	// �� �ܿ��� read, flush, is_open, close ���� �Լ� �̸��� ���
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
		printf("%s ����\n", s.c_str());
	}
};



int main()
{
	FileStream fs("a.txt");
	fs.write("hello");

	// �Ʒ��� ���� class�� �ִٰ� �����غ���.

	PipeStream ps("my named pipe");
	ps.write("hello");

	NetworkStream ns("100.100.100.100", 4000);
	ns.write("hello");
}
