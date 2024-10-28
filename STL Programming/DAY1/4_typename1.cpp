class Test
{
public:
	enum { value = 1 };
	using DWORD = int;
};
int p = 0;

template<typename T> void foo(T a)
{

	// "className::name" 에서 name은
	// 값 일 수 있고 : enum, static member 등
	// type 일 수 있다 : using, inner class 등

	// 아래 2줄에서 * 의 의미를 생각해 보세요(1. 곱하기, 2. 포인터 변수 선언)
//	Test::value * p;	// 1 * global variable p.  즉 곱하기임.
//	Test::DWORD * p;	// int *p : 선언, *는 포인터 연산자.


	// dependent name : 템플릿 인자 T에 의존해서 꺼내는 이름
	// /=> compiler는 무조건 이름의 의미를 "값"으로 해석한다.!!! 중요
	T::value * p2;		// 문제 없음. (값이니까)
//	T::DWORD * p2;		// error (값이 아닌데 컴파일러가 값으로 처리 진행해서. 왜? Dependen Name 이라서!)
	typename T::DWORD * p2;		// ok. DWORD를 type으로 해석해 달라는 의미.
}
int main()
{
	Test t;
	foo(t);
}
