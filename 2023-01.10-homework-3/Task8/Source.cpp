#include <iostream>

int main(int argc, char* argv[]) {
	int a = 0;
	int b = 0;
	int n = 0;
	std::cin >> a;
	std::cin >> b;
	std::cin >> n;
	if ((n < a < b) && (a - b % a) == n) {
		int k = b / a + 1;
		while (k > 0) {
			std::cout << ">A" << std::endl;
			std::cout << "A>B" << std::endl;
			k -= 1;
		}
	}
	if ((n < b < a) && (b - a % b) == n) {
		int k = a / b + 1;
		while (k > 0) {
			std::cout << ">B" << std::endl;
			std::cout << "B>A" << std::endl;
			k -= 1;
		}
	}
	if ((n > a || n > b) || (a % b == 0 && a != b && a != n) || (a != b && a != n && b % a == 0)) {
		std::cout << "Impossible";
	}
	if (n == a) {
		std::cout << ">A";
	}
	if (a != n and n == b) {
		std::cout << ">B";
	}
	return EXIT_SUCCESS;
}