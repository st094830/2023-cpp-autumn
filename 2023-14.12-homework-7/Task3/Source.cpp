#include <iostream>
#include <fstream>

char* newWord(const char* line, int start)
{
	int i = 0;
	char* word = (char*)malloc(sizeof(char));
	while (line[start + i] != ' ')
	{
		word[i] = line[start + i];
		i++;
	}
	return word;
}

int strStr(const char* line, const char* find)
{
	int start = 0;
	int end = 0;
	for (int i = 0; i < sizeof(line); ++i)
	{
		if (line[i] == find[0])
		{
			char* add = subStr(line, i, i + sizeof(find));
			if (strCmp(add, find) == 0)
			{
				return i;
			}
		}
	}
	return 0;
}

char* subStr(const char* line, int start, int end)
{
	int res = 0;
	char answer[70000];
	for (int i = 0; i <= end - start; ++i)
	{
		answer[i] = line[start + i];
	}
	return answer;
}

int min(int a, int b)
{
	return(a >= b ? a : b);
}
int strCmp(const char* a, const char* b)
{
	int notEqualPoint = 0;
	for (int i = 0; i < min(sizeof(a), sizeof(b)); ++i)
	{
		if (a[i] != b[i])
		{
			notEqualPoint = i + 1;
			break;
		}
	}
	if (!notEqualPoint)
	{
		return (sizeof(a) == sizeof(b) ? 0 : sizeof(a) + 1);
	}
}

void getText(std::istream& stream, char*& text_)
{
	stream >> text_;
}

int main(int argc, char* argv[])
{
	std::ifstream fin("in.txt");
	fin.open("in.txt");
	char* text = (char*)malloc(sizeof(char) * 1);
	getText(fin, text);
	fin.close();

	int numOfWords = scanf("%d", text);
	char** wordsList = (char**)malloc(sizeof(char*) * numOfWords);
	int* eachWordFreq = (int*)malloc(sizeof(int) * numOfWords);
	for (int i = 0; i < numOfWords; ++i)
	{
		char* word = newWord(text, i);
		bool notIn = true;
		for (int j = 0; j < numOfWords; ++j)
		{
			if (strCmp(word, wordsList[j]) == 0)
			{
				eachWordFreq[j]++;
				notIn = !notIn;
				break;
			}
		}
		if (notIn)
		{
			wordsList[i] = word;
			eachWordFreq[i]++;
		}
	}



	int mostFreqNumber = 0;
	for (int i = 0; i < sizeof(eachWordFreq); ++i)
	{
		if (eachWordFreq[mostFreqNumber] < eachWordFreq[i])
		{
			mostFreqNumber = i;
		}
	}

	std::ofstream fout("out.txt");
	fout.open("out.txt");
	fout << wordsList[mostFreqNumber] << std::endl;
	fout.close();

	return EXIT_SUCCESS;
}