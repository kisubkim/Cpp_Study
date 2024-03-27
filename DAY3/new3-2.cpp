#include <iostream>
#include <vector>
#include <memory>
class Point {
	int x, y;
	public:
		Point(int a, int b) : x(a), y(b) { std::cout << "Point()\n"; }
		~Point() { std::cout << "~Point()\n"; }
};

template<typename T, typename Ax = std::allocator<T>>
class vector
{
	T*  buff;
	std::size_t sz;
	std::size_t capacity;

	Ax ax;
	public:
		vector(std::size_t s) : sz(s), capacity(s) {
			//buff = new T[sz];		// 이렇게 하면, default constructor 가 없으면 container 에 할당이 불가함.
									//& 결론은 이렇게 안되어 있다! (T가 디폴드 생성자가 있어야 한다는 제약이 생김.)
			buff = static_cast<T*>(operator new(sizeof(T)*sz));
			for(int i=0; i<sz; i++)
				new(&buff[i]) T;

		}

		vector(std::size_t s, const T& value) : sz(s), capacity(s) {
			//buff = new T[sz];		// 이렇게 하면, default constructor 가 없으면 container 에 할당이 불가함.
									//& 결론은 이렇게 안되어 있다! (T가 디폴드 생성자가 있어야 한다는 제약이 생김.)
			//buff = static_cast<T*>(operator new(sizeof(T)*sz));		// 요렇게 하는 걸 아래처럼 하면 전략패턴으로 만듬.
			buff = ax.allocate(sz);


			// for(int i=0; i<sz; i++)
			// 	new(&buff[i]) T(value);

			std::uninitialized_fill_n(buff, sz, value);	//* 위 for문이 하는 일과 동일
		}
};

int main()
{
	Point pt(1,1);
	vector<Point> v(10, pt);

	vector<Point> v2(10, Point(1,1));
}
