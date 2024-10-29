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



int main()
{
	/*
	���Ͽ� �� �� "��ȣȭ" �ϴ� ����� �ʿ�.
	���̺귯�� ������ ���忡�� "�ּ��� ������"�� ������ ���ô�.
		
		1. FileStream �� �Ļ� Ŭ������ "EncryptStream" �� ������. (���)
			����
				a. FileStream �� �ƴ϶� �ٸ� NetworkStream, PipeStream �� �Ļ� Ŭ������ �ʿ�.
				b. ��ȣȭ �Ӹ� �ƴ϶� ���൵ �ʿ��ϴٸ� �ٽ� �Ļ� Ŭ���� �ʿ�����.
					=> ��ȣȭ ������ ���ÿ� �ʿ��ϸ� �ٽ� ���(���߻��) �ʿ�
		
		2. ��� Ŭ������ Stream �� "��ȣȭ ���" �߰�
			����
				a. �ʿ���� Stream ���� ��� ���� �ް� �ǰ�, ��� Ŭ������ ������ ��� �ҽ��� �ٽ� ������ �ؾ���.
				b. OCP ����. ���ο� �䱸������ ���� ������ "���� �ڵ� ����"
		
		3. Decorator Pattern
	*/

	FileStream fs("a.txt");
	fs.write("hello");

	EncryptDecorator ed(&fa);
	ed.write("hello");			// 1. Data�� ��ȣȭ �ϰ�
								// 2. fs.write(��ȣȭ�� data)
	ZipDecorator zd(&ed);
	zd.write("hello");			// 1. �����ϰ�
								// 2. ed.write(����� data)�� ��ȣȭ
								// 3. fs.write(�����ȣȭ�� data)

}
