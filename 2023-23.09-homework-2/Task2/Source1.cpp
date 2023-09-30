#include <iostream>

int main(int argc, char* argv[]) {
	int ts = 0;
	int sc = 0;
	std::cin >> ts;
	std::cin >> sc;
	if (((ts != 1) && (sc != 1)) || ((ts == 1) && (sc == 1))) {
		std::cout << "YES" << std::endl;
	}
	else {
		std::cout << "NO" << std::endl;
	}
	return 0;
}