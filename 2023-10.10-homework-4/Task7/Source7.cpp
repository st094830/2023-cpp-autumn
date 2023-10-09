#include <iostream>
#include <cstdlib>

int main(int, char**)
{
	int n = 0;
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

	int* numb_of_nonp = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if ((*(*(a + i) + j)) <= 0)
			{
				++(*(numb_of_nonp + i));
			}
		}
	}

	int** positive = (int**)malloc(sizeof(int*) * n);

	for (int i = 0; i < n; ++i)
	{
		*(positive + i) = (int*)malloc(sizeof(int) * (n - (*(numb_of_nonp + i))));
	}

	int delta = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < sizeof((*(positive + i))); ++j)
		{
			if ((*(*(a + i) + j)) > 0)
			{
				(*(*(positive + i) + j)) = (*(*(a + i) + j + delta));
			}
			else
			{
				++delta;
			}
		}
		delta = 0;
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < sizeof((*(positive + i))); ++j)
		{
			std::cout << (*(*(positive + i) + j)) << " ";
		}
		std::cout << std::endl;
	}


	for (int i = 0; i < n; ++i)
	{
		free(*(a + i));
	}
	free(a);

	free(numb_of_nonp);

	for (int i = 0; i < n; ++i)
	{
		free(*(positive + i));
	}
	free(positive);

	return EXIT_SUCCESS;
}
