template<typename T> class List
{	
public:
	void push_front(const T& a)
	{
		// lock()
		// ...
		// unlock()
		// 여렇게 하면 thread safe 함.
	}
};

List<int> st;	// st는 전역변수. 모든 thread가 공유. multithread env에서 안전 X

int main()
{
	// multithread 에서 안전할려면 기본적으로 아래처럼 해야함.
	// lock()
	st.push_front(10);
	// unlock();
}
