#include <iostream>
#include <thread>   // thread 관련 header
#include <chrono>
using namespace std::literals;

// std::this_thread namespace 
//^ ==> thread 관련 몇몇 일반함수 제공

int main()
{
    std::cout << std::this_thread::get_id() << std::endl;       // current thread id get.

    std::this_thread::sleep_for(3s);		

}


