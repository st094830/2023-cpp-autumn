#include <iostream>

void Hanoi(int n, int first, int last)
{
	if (n <= 0)
	{
		return;
	}
	int add = 6 - first - last;
	if (first + last == 4)
	{
		Hanoi(n, first, 2);
		Hanoi(n, 2, last);
	}
	else
	{
		Hanoi(n - 1, first, add);
		printf("%d %d %d\n", n, first, last);
		Hanoi(n - 1, add, last);
	}
}

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	Hanoi(n, 1, 3);
}