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

	int counter = 0; //блок подсчёта кол-ва положительных эл-тов
	for (int i = 0; i < n; ++i)
	{
		if (*(a + i) > 0)
		{
			++counter;
		}
	}
	std::cout << counter;

	free(a);

	return EXIT_SUCCESS;
}
