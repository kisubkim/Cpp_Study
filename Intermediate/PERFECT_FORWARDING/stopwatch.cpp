#include <iostream>
#include <chrono>

class StopWatch
{
public:
	StopWatch() : start(std::chrono::system_clock::now()) {}

	~StopWatch()
	{
		end = std::chrono::system_clock::now();
		// Time in double
		std::chrono::duration<double> elapsed = end - start;
		std::chrono::nanoseconds nano = end - start;

		std::cout << elapsed.count() << " seconds..." << std::endl;
	}
private:
	std::chrono::system_clock::time_point start;
	std::chrono::system_clock::time_point end;
};

int main()
{
	StopWatch sw;
	std::cout << "aaa" << std::endl;
}

