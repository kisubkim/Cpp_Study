class Dialog
{
public:
	void close(int code) {}

	static void close2(int code){}
};

void foo(int a) {}

int main()
{
	void(*f1)(int) = &foo;			 // ok
	void(*f1)(int) = &Dialog::close1; // ??
	void(*f1)(int) = &Dialog::close2; // ??
}