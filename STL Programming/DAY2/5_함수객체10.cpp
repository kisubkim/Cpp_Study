// 함수객체 2번 복사
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> v = {1,2,6,4,3,5,7,9, 8,10};
	
	// 주어진 구간에서 1번째 나오는 "3의 배수" 을 찾고 싶다.
	int k = 3; // 사용자가 입력한 값이라고 가정.

    //& lambda 는 "지역변수를 캡쳐" 할 수 있음.
    //& [k] : lambda 에서 k를 사용하겠다는 의미.
    auto ret2 = std::find_if(v.begin(), v.end(), [k](int n){ return n % k == 0; }); 
    // lambda 에서 캡쳐할 변수에 넣을 때, 참조도 넣을 수 있고,
    // 넣으면 선언 할 때, 같은 type으로 선언되서 진행됨. memory 자체는 안건드림.

    //---------------------------------
    class CompilerGeneratedName {
        int k;
        public:
        CompilerGeneratedName(int n) : k(n) {};
        inline auto operator()(int n) const {
            return n % k == 0;
        }
    };

    auto ret3 = std::find_if(v.begin(), v.end(), CompilerGeneratedName(k));

}


