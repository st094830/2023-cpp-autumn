#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	int value{ n };

	int bitsum = 0;
	while (n)
	{
		bitsum = bitsum + (value & 1);
		value = value >> 1;
	}
	std::cout << bitsum << std::endl;
	return EXIT_SUCCESS;
}
