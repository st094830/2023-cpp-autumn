#include <iostream>

int main(int argc, char* argv[]) {
	int a = 0;
	int b = 0;
	int c = 0;
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;
	if ((a >= b) && (a >= c)) {
		if (b >= c) {
			std::cout << c << " " << b << " " << a << std::endl;
		}
		else {
			std::cout << b << " " << c << " " << a << std::endl;
		}
	}
	else if ((b >= a) && (b >= c)) {
		if (a >= c) {
			std::cout << c << " " << a << " " << b << std::endl;
		}
		else {
			std::cout << a << " " << c << " " << b << std::endl;
		}
	}
	else {
		if (a >= b) {
			std::cout << b << " " << a << " " << c << std::endl;
		}
		else {
			std::cout << a << " " << b << " " << c << std::endl;
		}
	}
	return 0;
}