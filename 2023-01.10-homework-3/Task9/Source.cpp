#include <iostream>

int main(int argc, char* argv[]) 
{
	int a = 0;
	int b = 0;
	std::cin >> a;
	std::cin >> b;
	while (a != b)
	{
		if (a % 2 == 1) 
		{
			std::cout << "-1" << std::endl;
			a--;
		}
		else 
		{
			if (a / 2 >= b) 
			{
				std::cout << ":2" << std::endl;
				a = a / 2;
			}
			else 
			{
				while (a != b) 
				{
					std::cout << "-1" << std::endl;
					a--;
				}
			}
		}
	}

	return EXIT_SUCCESS;
}