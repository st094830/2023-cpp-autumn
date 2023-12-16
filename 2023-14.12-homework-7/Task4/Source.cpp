#include <iostream>
#include <fstream>

int palindrome(const char* line_)
{
	int halfSize = strlen(line_) / 2;
	for (int i = 0; i < halfSize; ++i)
	{
		if (line_[i] != line_[sizeof(line_) - i - 1])
		{
			return 0;
		}
	}
	return 1;
}


void getText(std::istream& stream, char*& text_)
{
	stream >> text_;
}


int main(int argc, char* argv[])
{
	std::ifstream fin("in.txt");
	fin.open("in.txt");
	char* line = (char*)malloc(sizeof(char*));
	getText(fin, line);
	fin.close();

	std::ofstream fout("out.txt");
	fout << palindrome(line) << std::endl;
	fout.close();

	return EXIT_SUCCESS;
}