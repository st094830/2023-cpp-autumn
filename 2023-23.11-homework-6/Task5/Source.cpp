#include <iostream>

void Hanoi(int n, int first, int last)
{
	if (n <= 0)
	{
		return;
	}
	int add = 6 - first - last;
	Hanoi(n - 1, first, add);
	printf("%d %d %d\n", n, first, last);
	Hanoi(n - 1, add, last);
}

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	int last = 3 - (n % 2);
	Hanoi(n, 1, last);

	int add = 5 - last;
	for (int i = n; i > 1; --i)
	{
		Hanoi(i - 1, last, add);
		int changer = add;
		add = last;
		last = changer;
	}
}