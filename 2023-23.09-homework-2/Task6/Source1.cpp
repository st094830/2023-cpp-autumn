#include <iostream>

int main(int argc, char* argv[]) {
	int k = 0;
	int m = 0;
	int n = 0;
	std::cin >> k;
	std::cin >> m;
	std::cin >> n;
	if (n > k) {
		std::cout << m * 2 + (n / k) * m * 2 << std::endl;
	}
	else if (n <= k) {
		std::cout << m * 2 << std::endl;
	}
	return 0;
}