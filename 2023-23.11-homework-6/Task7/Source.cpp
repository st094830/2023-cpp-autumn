#include <iostream>

int n[4] {0, 0, 0, 0};
int** d = new int* [4] {nullptr, new int[10], new int[10], new int[10]};

void shift(int first, int last)
{
	std::cout << d[first][n[first] - 1] << " " << first << " " << last << std::endl;
	d[last][n[last]++] = d[first][--n[first]];
}

void Better_hanoi(int count, int first, int last) 
{
	if (count == 0) 
	{
		return;
	}
	int add = 6 - first - last;
	Better_hanoi(count - 1, first, add);
	shift(first, last);
	Better_hanoi(count - 1, add, last);
}
 
//void Hanoi(int number, int first, int last) 
//{
//	if (number == 0) 
//	{
//		return;
//	}
//	int add = 6 - first - last;
//
//	Hanoi(number - 1, first, add);
//	shift(first, last);
//	Hanoi(number - 1, add, last);
//}

void sort() 
{
	int counter = 0;
	while (n[1] > 0) 
	{
		int k = d[1][n[1] - 1];
		for (int i = 0; i < n[3]; ++i) 
		{
			if (d[1][n[1] - 1] > d[3][n[3] - 1]) 
			{
				++counter;
			}
			else 
			{
				break;
			}
		}
		Better_hanoi(counter, 3, 2);
		shift(1, 3);
		Better_hanoi(counter, 2, 3);
		counter = 0;
	}
	while (n[3] > 0) 
	{
		Better_hanoi(d[3][n[3] - 1], 2, 3);
		int* changer_argv = d[2];
		int changer_argc = n[2];
		d[2] = d[3];
		n[2] = n[3];
		d[3] = changer_argv;
		n[3] = changer_argc;
	}
}

int main(int argc, char* argv[])
{
	std::cin >> n[1];
	for (int i = n[1] - 1; i >= 0; --i) 
	{
		std::cin >> d[1][i];
	}
	sort();
	return EXIT_SUCCESS;
}