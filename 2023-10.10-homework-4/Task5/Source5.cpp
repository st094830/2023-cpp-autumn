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

	// блок вывода массива в обратном порядке
	for (int i = n - 1; i >= 0; --i) 
	{
		for (int j = n - 1; j >= 0; --j) 
		{
			std::cout<<*(*(a + i) + j)<<" ";
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < n; ++i)
	{
		free(*(a + i));
	}
	free(a);

	return EXIT_SUCCESS;
}