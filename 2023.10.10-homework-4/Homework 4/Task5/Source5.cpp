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

	// блок вывода массива в обратном порядке
	for (int i = n - 1; i >= 0; --i)
	{
		std::cout << *(a + i) << " ";
	}
	std::cout << std::endl;

	free(a);

	return EXIT_SUCCESS;
}