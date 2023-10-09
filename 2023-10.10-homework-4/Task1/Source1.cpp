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

	int counter = 0; //блок подсчёта кол-ва положительных эл-тов
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (*(*(a + i) + j) > 0)
			{
				++counter;
			}
		}
	}
	std::cout << counter;

	for (int i = 0; i < n; ++i)
	{
		free(*(a + i));
	}
	free(a);

	return EXIT_SUCCESS;
}
