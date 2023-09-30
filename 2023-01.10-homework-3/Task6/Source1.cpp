#include <iostream>

int main(int argc, char* argv[]) {
	int n = 0;
	int a = 1;
	int b = 1;
	int c = 0;
	std::cin >> n;
	if (n > 2) {
		while ((n - 2) > 0)
		{
			c = a + b;
			a = b;
			b = c;
			n--;
		}
		std::cout << b << std::endl;
	}
	else {
		std::cout << 1 << std::endl;
	}
	return 0;
}