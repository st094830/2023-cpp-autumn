#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) 
{
	unsigned short a = 0;
	unsigned short b = 0;
	std::cin >> a;
	std::cin >> b;
	int summ = 0;
	int prev = 0;
	int useless_nulls = 0;
	for (int i = 0; i < 17; ++i) 
	{ 
		if ((!((a & ~(~0 << 1)))) && (!(b & ~(~0 << 1)))) 
		{
			++useless_nulls;
		}
		else 
		{
			useless_nulls = 0;
		}

		if (!(((a & ~(~0 << 1)) | (b & ~(~0 << 1))) ^ prev))
		{
			summ = summ + ((summ & ~(~0 << 1)) ^ (a & ~(~0 << 1)));
			summ = summ + ((summ & ~(~0 << 1)) ^ (b & ~(~0 << 1)));
			summ = summ + ((summ & ~(~0 << 1)) ^ prev);
			prev = 1;
		} 
		else {
			summ = summ + (a & ~(~0 << 1));
			summ = summ + (b & ~(~0 << 1));
			summ = summ + prev;
			prev = 0;
		}
		summ = summ << 1;
		a >> 1;
		b >> 1;
	}
	summ = summ >> (useless_nulls);
	std::cout << summ << std::endl;

	return EXIT_SUCCESS;
}