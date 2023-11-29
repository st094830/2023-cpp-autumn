#include <iostream>

int main(int argc, char* argv[]) 
{
	int n = 0;
	int s = 0;
	std::cin >> n;
	while (n / 10 > 0)
	{
		s = s * 10 + (n % 10);
		n = n / 10;
	}
	std::cout << s * 10 + n << std::endl;

	return EXIT_SUCCESS;
}