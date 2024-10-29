#define _CRT_SECURE_NO_WARNINGS	
#include <iostream>


/*


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

class ZipDecorator : public Stream {
	Stream* origin;
public:
	ZipDecorator(Stream* s) : origin(s) {}
	void write(const std::string& s) {
		auto s2 = "[" + s + "]" + "압축됨";		// 압축기능 추가
		origin->write(s2);
	}
};

class EncryptDecorator : public Stream {
	Stream* origin;
public:
	EncryptDecorator(Stream* s) : origin(s) {}
	void write(const std::string& s) {
		auto s2 = "[" + s + "]" + "암호화됨";		// 압축기능 추가
		origin->write(s2);
	}
};

int main()
{
	FileStream fs("a.txt");
	fs.write("hello");

	EncryptDecorator ed(&fs);
	ed.write("hello");			// 1. Data를 암호화 하고
	// 2. fs.write(암호화된 data)
	ZipDecorator zd(&ed);
	zd.write("hello");			// 1. 압축하고
	// 2. ed.write(압축된 data)를 암호화
	// 3. fs.write(압축암호화된 data)

}


/*
	구글에서 "C# Stream" 검색 후 "이미지 보기" 해보자.

	참고
		=> Python 에서도 decorator 는 아주 널리 사용됨.
		=> "@"로 시작하는 것이 decorator 임.

		@wrapped			// <== 이게 decorator 임.
		fn add(x, y):
			return x + y

		add(1, 2) => wrapped(1, 2) 를 먼저 실행 후 결과를 add 로 전달.
				  => wrapped() -> add()
				     기능 추가 후 -> 원본 호출
*/
