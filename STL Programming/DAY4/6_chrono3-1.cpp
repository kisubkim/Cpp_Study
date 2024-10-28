#include <iostream>
#include <chrono>
#include <thread>

using namespace std::literals;

int main()
{
	std::cout << "=============================\n";
	//? 현재 thread를 특정시간 동안 재우는 함수는 "std::this_thread::sleep_for"
	//? 3초간 재워보자

	//std::this_thread::sleep_for(std::chrono::seconds(3));
	std::this_thread::sleep_for(3s);
	std::cout << "=============================\n";
}