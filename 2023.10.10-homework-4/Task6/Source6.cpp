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

	// блок определения первого минимума и последнего максимума
	int mini = 0;
	int maxi = 0;
	for (int i = 0; i < n; ++i)
	{
		if ((*(a + i)) < (*(a + mini)))
		{
			mini = i;
		}
		if ((*(a + i)) >= (*(a + maxi)))
		{
			maxi = i;
		}
	}

	// блок перемены местами первого минимума и последнего максимума
	int swapper = 0;
	swapper = (*(a + mini));
	(*(a + mini)) = (*(a + maxi));
	(*(a + maxi)) = swapper;

	// блок вывода полученного массива
	for (int i = 0; i < n; ++i)
	{
		std::cout << (*(a + i)) << " ";
	}
	std::cout << std::endl;

	free(a);

	return EXIT_SUCCESS;
}