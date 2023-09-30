#include <iostream>

int main(int argc, char* argv[]) {
	int a = 0;
	int b = 0;
	int n = 0;
	int t = 0;
	int a_curt = 0;
	int b_curt = 0;
	std::cin >> a;
	std::cin >> b;
	std::cin >> n;
	if ((n <= a) || (n <= b))
	{
		if (((n + b) % a) == 0) {
			while ((n + b) > t)
			{

				if (b_curt + a_curt > b) {
					a_curt = a_curt - (b - b_curt);
					std::cout << ">B" << std::endl;
					std::cout << "A>B" << std::endl;
					b_curt = a_curt;
					a_curt = 0;
				}
				else {
					b_curt = b_curt + a_curt;
					a_curt = 0;
				}
				t = t + a;
				a_curt = a;
				std::cout << ">A" << std::endl;
				std::cout << "A>B" << std::endl;
			}
		}
		else if (((a + n) % (b)) == 0) {
			while ((a + n) > t)
			{

				if (b_curt + a_curt > a) {
					b_curt = b_curt - (a - a_curt);
					std::cout << ">A" << std::endl;
					std::cout << "B>A" << std::endl;
					a_curt = b_curt;
					b_curt = 0;
				}
				else {
					a_curt = a_curt + b_curt;
					b_curt = 0;
				}
				t = t + b;
				b_curt = b;
				std::cout << ">B" << std::endl;
				std::cout << "B>A" << std::endl;
			}
		}
		else if ((b - n) % (a) == 0) {
			while ((b - n) > t)
			{

				if (b_curt + a_curt > b) {
					a_curt = a_curt - (b - b_curt);
					std::cout << ">B" << std::endl;
					std::cout << "A>B" << std::endl;
					b_curt = a_curt;
					a_curt = 0;
				}
				else {
					b_curt = b_curt + a_curt;
					a_curt = 0;
				}
				t = t + a;
				a_curt = a;
				std::cout << ">A" << std::endl;
				std::cout << "A>B" << std::endl;
			}
		}
		else if (((a - n) % (b)) == 0) {
			while ((a - n) > t)
			{

				if (b_curt + a_curt > a) {
					b_curt = b_curt - (a - a_curt);
					std::cout << ">A" << std::endl;
					std::cout << "B>A" << std::endl;
					a_curt = b_curt;
					b_curt = 0;
				}
				else {
					a_curt = a_curt + b_curt;
					b_curt = 0;
				}
				t = t + b;
				b_curt = b;
				std::cout << ">B" << std::endl;
				std::cout << "B>A" << std::endl;
			}
		}
		else {
			std::cout << "Impossible" << std::endl;
		}
	}
	else {
		std::cout << "Impossible" << std::endl;
	}
	return 0;
}