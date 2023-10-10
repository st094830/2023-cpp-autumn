#include <iostream>
#include <cstdlib>

int main(int, char**)
{
	int n = 0; //блок создания массива
	std::cin >> n;
	int* a = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; ++i)
	{
		int r = 0;
		std::cin >> r;
		*(a + i) = r;
	}

	for (int i = 0; i < n; ++i) //блок вывода элементов, стоящих на четных местах, в одну строку.
	{
		if (i % 2 == 1)
		{
			std::cout << *(a + i) << " ";
		}
	}
	std::cout << std::endl;

	free(a);

	return EXIT_SUCCESS;
}
