#include <iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	std::cin >> a;
	std::cin >> b;
	int c = float(a + b) / 2 + float(abs(a - b)) / 2;
	std::cout << c << std::endl;

	return EXIT_SUCCESS;
}
