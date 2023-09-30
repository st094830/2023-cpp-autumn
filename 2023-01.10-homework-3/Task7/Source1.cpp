#include <iostream>

int main(int argc, char* argv[]) {
	int n = 0;
	int k = 0;
	int s = 0;
	int pow_ten = 1;
	int pow_two = 1;
	std::cin >> n;
	while (n>0)
	{
		s = s + (n % 2)* pow_ten;
		pow_ten = pow_ten * 10;
		n = n / 2;
	}
	while (s > pow_two)
	{
		pow_two = pow_two * 10;
		k++;
	}
	std::cout << k << std::endl;
	return 0;
}