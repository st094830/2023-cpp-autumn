#include <iostream>

int main(int argc, char* argv[]) {
	int a = 0;
	std::cin >> a;
	if (a < 5) {
		std::cout << a << " 0 0 0 0" << std::endl;
	}
	else if (a < 10) {
		std::cout << a % 5 << " " << a / 5 << " 0 0 0" << std::endl;
	}
	else if (a < 20) {
		std::cout << a % 5 << " " << (a % 10) / 5 << " " << a / 10 << " 0 0" << std::endl;
	}
	else if (a < 60) {
		std::cout << a % 5 << " " << (a % 10) / 5 << " " << (a % 20) / 10 << " " << a / 20 << " 0" << std::endl;
	}
	else {
		std::cout << a % 5 << " " << (a % 10) / 5 << " " << (a % 20) / 10 << " " << (a % 60) / 20 << " " << a / 60 << std::endl;
	}
	return 0;
}