
// STL의 다양한 곳에서 널리 사용되는 기법.
template<class T>
T square(T a){
    return a*a;
}

template<typename T>
class List{
    public:
        List(int sz, T value) {}
};

// C++14까지는 class template의 타입 추론이 안됨으로 복잡해 보이는 경우가 많았음.
// 이 경우, 아래 기법 사용
//* class template 객체를 생성하는 함수 template 사용
//* "Object Generator" 라고 불림.
// class template의 instance를 만드는 function template
// google "c++ IDioms" 검색
template<typename T>
List<T> make_list(int sz, T value){
    return List<T>(sz, value);
}


int main()
{
    // 다음중 편리해 보이는 것은?
    square<int>(3); // 원래는 이게 맞음. 정확힌 표기법. 근데 귀찮아.
    square(3);      // type parameter 생략 가능. 인자 3으로 T 타입 추론 => 편리하지. 이거 c++17부터 가능?. No. 함수 템플릿 생략은 99부터 가능

    List<int> s1(10,3); // ok
    List s2(10,3);  // ok? ok! class template의 경우 생성자를 통한 타입추론은 C++17부터 가능.

    auto a3 = make_list<int>(10,3);      // 요게 정식 표기
    auto ar = make_list(10, 3);         // 함수 템플릿은 C++99 부터 가능
}