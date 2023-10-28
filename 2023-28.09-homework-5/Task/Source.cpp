#include <iostream>
#include <cstdlib>
#include <ctime>

void PrintArray(int* a, int len);
void AddElement(int*& a, int& len, int ev);
void DeleteElement(int*& a, int& len, int index);
void SortArray(int*& a, int& len);
void ReverseArray(int*& a, int& len);
void ChangeFMaxLMin(int*& a, int& len);
void DeleteRepeats(int*& a, int& len);
void ExpandArray(int*& a, int& len, int n);
void ChangeSize(int*& a, int& len, int size);
void PrintMenu();

int main(int argc, char* argv[])
{
	int len = 0;
	int* a = nullptr;
	bool exit = false;
	while (!exit) {
		{
			system("cls");
			PrintMenu();
		}
		int option = 0;
		{
			std::cin >> option;
		}
		{
			switch (option)
			{
			case 0:
				exit = true;
				break;
			case 1:
				PrintArray(a, len);
				system("pause");
				break;
			case 2:
			{
				int ev = 0;
				std::cin >> ev;
				AddElement(a, len, ev);
				break;
			}
			case 3:
			{
				int index = 0;
				std::cin >> index;
				DeleteElement(a, len, index);
				break;
			}
			case 4:
				SortArray(a, len);
				break;
			case 5:
				ReverseArray(a, len);
				break;
			case 6:
				ChangeFMaxLMin(a, len);
				break;
			case 7:
				DeleteRepeats(a, len);
				break;
			case 8:
			{
				int n = 0;
				std::cin >> n;
				ExpandArray(a, len, n);
				break;
			}
			default:
				std::cout << "Unknown command" << std::endl;
				break;
			}
		}

	}

	return EXIT_SUCCESS;
}

void PrintArray(int* a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}

void AddElement(int*& a, int& len, int ev)
{
	ChangeSize(a, len, 1);
	a[len - 1] = ev;
}

void DeleteElement(int*& a, int& len, int index)
{
	int* newA = new int[len - 1] {0};
	if (a != nullptr)
	{
		int delta = 0;
		for (int i = 0; i < len; ++i)
		{
			if (i == index)
			{
				++i;
				delta = 1;
			}
			newA[i - delta] = a[i];
		}
		delete[] a;
	}
	a = newA;
	--len;
}

void SortArray(int*& a, int& len)
{
	if (a != nullptr)
	{
		for (int i = 0; i < len - 1; ++i)
		{
			if (a[i] > a[i + 1])
			{
				int changer = 0;
				changer = a[i];
				a[i] = a[i + 1];
				a[i + 1] = changer;
			}
		}
	}
}

void ReverseArray(int*& a, int& len)
{
	if (a != nullptr)
	{
		for (int i = 0; i < (len / 2 + len % 2); ++i)
		{
			int changer = 0;
			changer = a[i];
			a[i] = a[len - 1 - i];
			a[len - 1 - i] = changer;
		}
	}
}

void ChangeFMaxLMin(int*& a, int& len)
{
	if (a != nullptr)
	{
		int firstMaxIndex = a[0];
		int lastMinIndex = a[0];
		for (int i = 0; i < len; ++i)
		{
			if (a[i] <= a[lastMinIndex])
			{
				lastMinIndex = i;
			}
			if (a[i] > a[firstMaxIndex])
			{
				firstMaxIndex = i;
			}
		}
		int swapper = 0;
		swapper = a[lastMinIndex];
		a[lastMinIndex] = a[firstMaxIndex];
		a[firstMaxIndex] = swapper;
	}
}

void DeleteRepeats(int*& a, int& len)
{
	int* midA = new int[len] {0};
	int newlen = 0;
	if (a != nullptr)
	{
		for (int i = 0; i < len; ++i)
		{
			bool checker = true;
			for (int j = 0; j < i; ++j)
			{
				if (a[j] == a[i]) {
					checker = false;
				}
			}
			if (checker)
			{
				midA[newlen] = a[i];
				++newlen;
			}
		}
		delete[] a;
	}
	int* newA = new int[newlen] {0};
	for (int i = 0; i < newlen; ++i)
	{
		newA[i] = midA[i];
	}
	a = newA;
	len = newlen;
}

void ExpandArray(int*& a, int& len, int n)
{
	srand(time(0));

	int prevLen = 0;
	prevLen = len;
	ChangeSize(a, len, n);
	for (int i = prevLen; i < len; ++i)
	{
		a[i] = rand();
	}
}

void ChangeSize(int*& a, int& len, int size)
{
	int* newA = new int[len + size] {0};
	if (a != nullptr)
	{
		for (int i = 0; i < len; ++i)
		{
			newA[i] = a[i];
		}
		delete[] a;
	}
	a = newA;
	len = len + size;
}

void PrintMenu()
{
	std::cout << "0 - exit program" << std::endl;
	std::cout << "1 - print array" << std::endl;
	std::cout << "2 - add element to array" << std::endl;
	std::cout << "3 - delete element from array" << std::endl;
	std::cout << "4 - sort array in ascending order" << std::endl;
	std::cout << "5 - reverse array" << std::endl;
	std::cout << "6 - swap first maximum and last minimum elements of array" << std::endl;
	std::cout << "7 - delete all duplications from array" << std::endl;
	std::cout << "8 - add n random elements to array" << std::endl;
}
