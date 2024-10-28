#include <iostream>
#include <chrono>

using Meter = std::chrono::duration<int>;
using KiloMeter = std::chrono::duration<int, std::kilo>;
using CentiMeter = std::chrono::duration<int, std::centi>;

KiloMeter operator""_km(unsigned long long n) {
	return KiloMeter(static_cast<int>(n));
}

Meter operator""_m(unsigned long long n) {
	return Meter(static_cast<int>(n));
}

int main()
{

	auto k1 = 2_km;		// 사용자가 뒤에 operator를 만들려면 "_"를 붙이고 만들어야함.
						// 3.4 가 double 인데 3.4f 하면 float 형 되는 것과 유사.
	auto k2 = 3_km;

	Meter m = k1 + 30_m + k2;

	std::cout << m.count() << std::endl;

}
