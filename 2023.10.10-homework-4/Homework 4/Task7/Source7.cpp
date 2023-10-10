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

	//блок исключения из массива неположительных эл-тов
	int delta = 0;
	for (int i = 0; i < n; ++i)
	{
		if (*(a + (i + delta)) <= 0)
		{
			int s = i;
			while ((*(a + (s + delta)) <= 0) && (i < n)) 
			{
				*(a + (s + delta)) = *(a + (i + 1 + delta));
				++i;
			}
			delta = delta + i - s;
		}
	}

	//вывод полученного массива
	for (int i = 0; i < n - delta; ++i)
	{
		std::cout << (*(a + i)) << " ";
	}
	std::cout << std::endl;

	free(a);

	return EXIT_SUCCESS;
}