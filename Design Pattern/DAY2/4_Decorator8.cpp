#define _CRT_SECURE_NO_WARNINGS	
#include <iostream>


/*


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

class ZipDecorator : public Stream {
	Stream* origin;
public:
	ZipDecorator(Stream* s) : origin(s) {}
	void write(const std::string& s) {
		auto s2 = "[" + s + "]" + "�����";		// ������ �߰�
		origin->write(s2);
	}
};

class EncryptDecorator : public Stream {
	Stream* origin;
public:
	EncryptDecorator(Stream* s) : origin(s) {}
	void write(const std::string& s) {
		auto s2 = "[" + s + "]" + "��ȣȭ��";		// ������ �߰�
		origin->write(s2);
	}
};

int main()
{
	FileStream fs("a.txt");
	fs.write("hello");

	EncryptDecorator ed(&fs);
	ed.write("hello");			// 1. Data�� ��ȣȭ �ϰ�
	// 2. fs.write(��ȣȭ�� data)
	ZipDecorator zd(&ed);
	zd.write("hello");			// 1. �����ϰ�
	// 2. ed.write(����� data)�� ��ȣȭ
	// 3. fs.write(�����ȣȭ�� data)

}


/*
	���ۿ��� "C# Stream" �˻� �� "�̹��� ����" �غ���.

	����
		=> Python ������ decorator �� ���� �θ� ����.
		=> "@"�� �����ϴ� ���� decorator ��.

		@wrapped			// <== �̰� decorator ��.
		fn add(x, y):
			return x + y

		add(1, 2) => wrapped(1, 2) �� ���� ���� �� ����� add �� ����.
				  => wrapped() -> add()
				     ��� �߰� �� -> ���� ȣ��
*/