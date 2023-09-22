#include <iostream>

int main(int argc, char* argv[]) {
	int a = 0;
	std::cin >> a;
	if ((a > 10) && (a < 20)) {
		std::cout << a << " bochek" << std::endl;
	}
	else if (a % 10 == 1) {
		std::cout << a << " bochka" << std::endl;
	}
	else if ((a % 10 > 1) && (a % 10 < 5)) {
		std::cout << a << " bochki" << std::endl;
	}
	else {
		std::cout << a << " bochek" << std::endl;
	}
	return 0;
}