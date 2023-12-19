#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>


// returns string which contains given [a] and [b] strings back-to-back. ₍^._.^₎ 𐒡

char* strCat(const char* a, const char* b)
{
	char* sumStr = (char*)malloc(sizeof(char) * (sizeof(a) + sizeof(b)));
	for (int i = 0; i < sizeof(a); ++i)
	{
		sumStr[i] = a[i];
	}
	for (int j = 0; j < sizeof(b); ++j)
	{
		sumStr[j + sizeof(a)] = b[j];
	}
	return sumStr;
}

//finds given [find] in [line], if there are no matches 0 is returned.

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


// returns part of the given string from [start] symbol to [end] symbol.

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




// strings are compared until one ends. 
// If they have defferences before one of them ends, strCmp returns the number of symbol. 
// If they are completely equal, strCmp returns 0;

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

//multiplicates string by number.

char* strMult(const char* c, int n)
{
	char* r = (char*)malloc(sizeof(c) * n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < sizeof(c); ++j)
		{
			r[j + sizeof(c) * i] = c[j];
		}
	}
	return r;
}