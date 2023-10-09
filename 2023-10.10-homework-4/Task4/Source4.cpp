#include <iostream>
#include <cstdlib>

int main(int, char**)
{
	int n = 0; //блок создания массива
	std::cin >> n;
	int** a = (int**)malloc(sizeof(int*) * n);

	for (int i = 0; i < n; ++i)
	{
		*(a + i) = (int*)malloc(sizeof(int) * n);
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int r = 0;
			std::cin >> r;
			*(*(a + i) + j) = r;
		}
	}

	int maximum = (*(*(a + 0) + 0)); //блок поиска и вывода максимума.
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			maximum = std::max(maximum, (*(*(a + i) + j)));
		}
	}
	std::cout << maximum << std::endl;

	for (int i = 0; i < n; ++i)
	{
		free(*(a + i));
	}
	free(a);

	return EXIT_SUCCESS;
}
