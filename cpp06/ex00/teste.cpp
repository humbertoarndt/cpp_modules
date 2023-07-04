#include <cmath>	// std::isnan, std::isinf
#include <cstdlib>	// std::atoi
#include <iostream>	// std::cout, std::cerr
#include <limits>	// std::numeric_limits

#define LOG(x) std::cout << x << std::endl;

int main(void)
{
	int	c = 84;

	LOG("> char:\t\t" << static_cast<char>(c));
	LOG("> int:\t\t" << static_cast<int>(c));
	LOG("> float:\t" << static_cast<float>(c) << "f");
	LOG("> double:\t" << static_cast<double>(c));
	return (0);
}