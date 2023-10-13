#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			std::cout << abs(std::min(abs((n / 2 + n % 2) - (j + 1)), abs((n / 2 + n % 2) - (i + 1))) - (n / 2 + n % 2)) << " ";
		}
		std::cout << std::endl;
	}

	return EXIT_SUCCESS;
}
