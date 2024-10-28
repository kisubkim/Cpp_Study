#include <algorithm>

int main()
{
    int n1 = std::max(1, 3); // c++98 표준, max는 함수(template)임.
    int n2 = std::ranges::max(1, 3);    // C++20에서 추가
    int n3 = std::ranges::max.operator()(1, 3); // 함수객체로 만든 것.
}