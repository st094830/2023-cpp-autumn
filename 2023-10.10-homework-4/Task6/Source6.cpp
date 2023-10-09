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

	// блок определения первого минимума и последнего максимума
	int mini = 0;
	int minj = 0;
	int maxi = 0;
	int maxj = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if ((*(*(a + i) + j)) < (*(*(a + mini) + minj))) 
			{
				mini = i;
				minj = j;
			}
			if ((*(*(a + i) + j)) >= (*(*(a + maxi) + maxj)))
			{
				maxi = i;
				maxj = j;
			}
		}
	}

	// блок перемены местами первого минимума и последнего максимума
	int swapper = 0;
	swapper = (*(*(a + mini) + minj));
	(*(*(a + mini) + minj)) = (*(*(a + maxi) + maxj));
	(*(*(a + maxi) + maxj)) = swapper;

	// блок вывода полученного массива
	for (int i = 0; i < n; ++i) 
	{
		for (int j = 0; j < n; ++j) 
		{
			std::cout << (*(*(a + i) + j)) << " ";
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