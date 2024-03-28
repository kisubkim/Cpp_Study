

class Vector {
    public:
        //Vector(int sz) {}
        //& explicit constructor : direct initialization 가능. copy initialization 불가능.
        explicit Vector(int sz) {}
};

void foo(Vector v) {}

int main(){
    //^ 인자가 한개인 생성자가 있으면 아래 4가지 형태로 객체 생성이 가능
    Vector v1(10);      // direct initialization (직접 초기화)
    Vector v2 = 10;     // copy initialization (복사 초기화)
    Vector v3{10};      // c++11
    Vector v4 = {10};   // c++11

    // 함수의 인자 전달은 copy initialization
    foo(10);        //& error 안남. 이건 Vector v = 10 이랑 같은 거임.
    // 위에 explicit 선언해서 사용하면 compile 안됨.
}