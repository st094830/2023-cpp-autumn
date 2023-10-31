#include <iostream>

int main(int argc, char* argv[])
{
	unsigned long n = 0;
	std::cin >> n;

	unsigned long c = 0;
	for (int i = 0; i < 4; i++)
	{
		c = c | ((n << (24 - 8 * i)) >> (8 * i));
	}
	std::cout << c << std::endl;

	return EXIT_SUCCESS;
}