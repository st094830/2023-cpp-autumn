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

	int maximum = (*(a + 0)); //блок поиска и вывода максимума.
	for (int i = 0; i < n; ++i)
	{
		maximum = std::max(maximum, (*(a + i)));
	}
	std::cout << maximum << std::endl;

	free(a);

	return EXIT_SUCCESS;
}
