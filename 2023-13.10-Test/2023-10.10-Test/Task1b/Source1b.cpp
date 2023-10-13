#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;

	int firstnnul = 0;
	int lastnnul = 0;

	int i = 0;
	unsigned int wasten = n;
	while (wasten)
	{
		++i;
		if ((wasten & ~(~0 << 1)) && (firstnnul != 0))
		{
			firstnnul = i;
		}
		if ((wasten & ~(~0 << 1)) && (lastnnul == 0))
		{
			lastnnul = i;
		}
		wasten = wasten >> 1;
	}

	int old_n_needed_part = n >> lastnnul;
	int new_n = 2;
	for (int j = 0; j < firstnnul; ++j)
	{
		new_n = new_n + (~(old_n_needed_part & ~(~0 << 1)));
		new_n = new_n << 1;
	}
	std::cout << ((new_n + 1) << lastnnul);

	return EXIT_SUCCESS;
}