#include <iostream>

void Hanoi(int n, int first, int last)
{
	if (n <= 0)
	{
		return;
	}
	int add = 6 - first - last;
	if (n == 1) 
	{
		printf("1 %d %d\n", first, last);
	}
	else 
	{ 
		Hanoi(n - 1, first, last);
		Hanoi(n - 2, last, add);
		printf("0 %d %d\n", first, last);
		Hanoi(n - 2, add, first);
		Hanoi(n - 1, first, last);
	}
}

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	Hanoi(n, 1, 3);
}