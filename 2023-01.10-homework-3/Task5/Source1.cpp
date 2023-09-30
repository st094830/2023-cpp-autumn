#include <iostream>

int main(int argc, char* argv[]) {
	int k = 0;
	int s = 0;
	int l = 0;
	int counter = 0;
	std::cin >> k;
	for (int i = 1; i <= k; i++)
	{
		l = i;
		while (l / 10 > 0)
		{
			s = s * 10 + (l % 10);
			l = l / 10;
		}
		s = s * 10 + l;
		if (s == i) {
			counter++;
		}
		s = 0;
	}
	std::cout << counter << std::endl;
	return 0;
}