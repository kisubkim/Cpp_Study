#include <thread>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>

constexpr std::size_t sz = 1'000'000;

std::vector<int> v;

void init()
{
    v.reserve(sz);
    for (int i = 0; i < sz; ++i)
    {
        v.push_back(i);
    }
}
//---------------------------------------------
template<typename T, typename R>
void sum(T first, T last, R& result)
{
    result = std::accumulate(first, last, result);
}

template<typename T, typename R>
void parallel_sum(T first, T last, R& result)
{
    const std::size_t cnt_per_thread = 25;
    const std::size_t cnt_element = std::distance(first, last); // element count
    if (cnt_element == 0) return;

    // each thread has 25 data. 25개씩 분배할 때 필요한 thread 갯수.
    const std::size_t max_cnt_thread = (cnt_element + cnt_per_thread-1) / cnt_per_thread;       // 필요한 thread 갯수

    // current HW's CPU core count.
    std::size_t cnt_hw_thread = std::thread::hardware_concurrency();
    if (cnt_hw_thread == 0) {
        cnt_hw_thread = 2;
    }
    //std::cout << cnt_hw_thread << std::endl;

    // 실제 HW core 갯수와 element 수를 고려한 숫자중 작은 값
    const std::size_t cnt_thread = std::min(max_cnt_thread, cnt_hw_thread);
    //-----------------------------------------------------------------
    std::size_t block_size = cnt_element / cnt_thread;

    std::vector<std::thread> thread_vec(cnt_thread-1);      //? 여기서 -1 한 이유는 main thread 도 같이 처리한다고 했을 때
                                                            //? sub thread 개수임. 꼭 이럴 필요는 없음.
    // T : iterator type
    // R : resultn type 
    std::vector<R> result_vec(cnt_thread, 0);

    T start = first;
    for (int i=0; i<cnt_thread-1; i++){
        T end = std::next(start, block_size);

        // thread 생성
        thread_vec[i] = std::thread(&sum<T, R>, start, end, std::ref(result_vec[i]));
        start = end;
    }

    // 마지막 구간은 main thread가 처리
    sum(start, last, result_vec[cnt_thread-1]);

    // 모든 thread join
    for (auto& t : thread_vec){
        t.join();
    }

    // result_vec 결과 취합
    result = std::accumulate(result_vec.begin(), result_vec.end(), 0);
}

int main()
{
    init();

    long long s = 0, s2 = 0;
    sum(v.begin(), v.end(), s);
    parallel_sum(v.begin(), v.end(), s2);

    std::cout << "single : " << s << std::endl;
    std::cout << "multi : " << s2 << std::endl;
}
