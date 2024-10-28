// 디자인 패턴을 계속 공부하면 
// => 어느 순간, 다양한 패턴이 유사해 보이기 시작합니다.
// => 이때는 항상 "의도" 를 생각하세요

// decorator vs object adapter 는 코드가 유사해 보입니다.

// Decorator
class ZipDecorator : public Stream
{
	Stream* stream;
public:
	ZipDecorator(Stream* s) : stream(s) {}

	void write(const std::string& s) override
	{
		auto data = "[ " + s + " 압축됨 ]";

		stream->write(data);
	}
};

// ObjectAdapter
class ObjectAdapter : public Shape
{
	TextView* tview;
public:
	ObjectAdapter(TextView* t) : tview(t) {}

	void draw() override
	{
		tview->show();
	}
};


FileStream fs("a.txt");
ZipDecorator zd(&fs);

fs.write("hello");
zd.write("hello");


TextView tv("hello");
ObjectAdapter oa(&tv);

tv.show();
oa.draw();
