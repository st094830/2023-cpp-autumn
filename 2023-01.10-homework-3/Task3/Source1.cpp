#include <iostream>

int main(int argc, char* argv[]) {
	long n = 0;
	int i = 1;
	int counter = 0;
	std::cin >> n;
	while (i * i <= n) {
		if (i * i == n) {
			counter++;
			break;
		}
		else if (n % i == 0) {
			counter = counter + 2;
		}
		i++;
	}
	std::cout << counter << std::endl;
	return 0;
}