#include <iostream>

int main(int argc, char* argv) {
	int a;
	std::cin >> a;
	int d = a / 10;
	int u = a % 10;
	//dozens
	switch (d) {
	case 1:
		std::cout << "X";
		break;
	case 2:
		std::cout << "XX";
		break;
	case 3:
		std::cout << "XXX";
		break;
	case 4:
		std::cout << "XL";
		break;
	case 5:
		std::cout << "L";
		break;
	case 6:
		std::cout << "LX";
		break;
	case 7:
		std::cout << "LXX";
		break;
	case 8:
		std::cout << "LXXX";
		break;
	case 9:
		std::cout << "LC";
		break;
	case 10:
		std::cout << "C";
		break;
	}
	//units
	switch (u) {
	case 1:
		std::cout << "I" << std::endl;
		break;
	case 2:
		std::cout << "II" << std::endl;
		break;
	case 3:
		std::cout << "III" << std::endl;
		break;
	case 4:
		std::cout << "IV" << std::endl;
		break;
	case 5:
		std::cout << "V" << std::endl;
		break;
	case 6:
		std::cout << "VI" << std::endl;
		break;
	case 7:
		std::cout << "VII" << std::endl;
		break;
	case 8:
		std::cout << "VIII";
		break;
	case 9:
		std::cout << "IX";
		break;
	}
	return 0;
}