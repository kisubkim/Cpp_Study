#include <vector>
#include <string>

void f1(std::vector<int> v) {}
void f2(std::string s) {}

int main() {
    f2("hello");            // 이게 자연스러워.
    std::string s1 = "hello";   // 그래서 이것도 됨.
    std::string s2("hello");    // ok
    //^ string 의 constructor 는 explicit이 아님.

    f1(10);     // 이상함.
    std::vector<int> v1 = 10;   // 그래서 이것도 안됨.
    std::vector<int> v2(10);    // 요거는 돰,
    //^ vector의 constructor는 explicit 으로 선언되었음.
}