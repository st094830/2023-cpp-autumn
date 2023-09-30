#include <iostream>

int main(int argc, char* argv[]) {
	int n = 0;
	int count = 1;
	std::cin >> n;
	for (int i = 1; i <= n; i++) 
	{
		if (n - count >= i) {
			for (int j = 1; j <= i; j++)
			{
				std::cout << i << " ";
			}
		}
		else {
			for (int j = 1; j <= n - count; j++)
			{
				std::cout << i << " ";
			}
			std::cout << i << std::endl;
			break;
		}
		count = count + i;
		
	}
	return 0;
}