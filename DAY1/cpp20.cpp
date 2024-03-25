#include <vector>
#include <algorithm>

int main() {
    std:;vector<int> v{1,2,3,4,5};
    auto ret1 = std::find(v.begin(), v.end(), 3);
    auto ret2 = std::find(v, 3);        // 이렇게 사용하게 할 수는 없었을까? 왜 안되었는지는 2일차에 배우자


    // c++20 의 concept 문법으로 해결.
    auto ret3 = std::ranges::find(v.begin(), v.end(), 3);
    auto ret4 = std::ranges::find(v, 3);        // 요거는 된다.

}