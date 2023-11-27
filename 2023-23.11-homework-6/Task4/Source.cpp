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
		printf("%d %d %d\n", n, first, last);
	}
	else
	{
		Hanoi(n - 1, first, last);
		printf("%d %d %d\n", n, first, add);
		Hanoi(n - 1, last, first);
		printf("%d %d %d\n", n, add, last);
		Hanoi(n - 1, first, last);
	}
}

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	Hanoi(n, 1, 3);
}