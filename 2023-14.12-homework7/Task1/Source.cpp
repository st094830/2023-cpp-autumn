#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>

void CountSize(char* filename, int& lines, int& maxLine)
{
	FILE* file = fopen(filename, "r");

	int currentLen = 0;
	while (!feof(file))
	{
		char c = 0;
		fscanf_s(file, "%c", &c);
		if (c == '\n')
		{
			lines++;
			currentLen = 0;
		}
		else
		{
			currentLen++;
		}
		maxLine = (maxLine > currentLen ? maxLine : currentLen);
	}
	lines++;
	fclose(file);
}


void ReadLines(char* filename, char** lines, int maxlen)
{
	FILE* file = fopen(filename, "r");

	int ind = 0;
	while (!feof(file))
	{
		fgets(lines[ind], maxlen, file);
		ind++;
	}

	fclose(file);
}


bool sentEnd(char c)
{
	return (c == '.' || c == '!' || c == '?');
}


bool wordEnd(char c)
{
	return (c == '\0' || c == ' ');
}

char* strCpy(char* destination, const char* source) {
	int res = 0;
	while (source[res + 1] != '\0')
	{
		destination[res] = source[res];
		res++;
	}
	return destination;
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

int main(int argc, char** argv)
{
	int w = 0;
	int h = 0;
	char filename[255];
	strCpy(filename, "in.txt");
	CountSize(filename, h, w);
	char** lines = (char**)malloc(sizeof(char*) * h);
	for (int i = 0; i < h; ++i)
	{
		lines[i] = (char*)malloc(sizeof(char) * w);
	}
	ReadLines(filename, lines, w);

	//turning file into a single string
	char* text = (char*)malloc(sizeof(char) * (h * w));

	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			text[i * w + j] = lines[i][j];
		}
	}

	int currentLength = 0;
	int index = 0;
	int currtSent = 0;
	int** lengths = (int**)malloc(sizeof(int*) * (h * w));
	for (int i = 0; i < h * w; ++i)
	{
		*(lengths + i) = (int*)malloc(sizeof(int) * 2);
	}
	char** sentences = (char**)malloc(sizeof(char*) * (h * w));
	for (int i = 0; i < h * w; ++i)
	{
		char* sentence = (char*)malloc(sizeof(char) * (h * w));
		sentences[i] = sentence;
	}
	lengths[0][0] = 1;
	for (int i = 0; i < h * w - 1; ++i)
	{
		if (wordEnd(text[i]))
		{
			currentLength++;
		}
		sentences[currtSent][index] = text[i];
		if (sentEnd(text[i]))
		{
			currentLength++;
			sentences[currtSent][index] = text[i];
			lengths[currtSent][1] = currentLength;
			lengths[currtSent + 1][0] = i;
			currtSent++;
		}
	}

	int longestSentenceStart = 0;
	int longestSentenceEnd = 0;
	int maximumLength = 0;
	for (int i = 0; i <= currtSent; ++i)
	{
		if (lengths[i][1] > maximumLength)
		{
			maximumLength = lengths[i][1];
			longestSentenceStart = lengths[i][0];
			longestSentenceEnd = lengths[i + 1][0] - 1;
		}
	}

	FILE* f = fopen("out.txt", "w");

	fprintf(f, "%s", subStr(text, longestSentenceStart, longestSentenceEnd));
	fclose(f);

	for (int i = 0; i < h; ++i)
	{
		free(lines[i]);
	}
	free(lines);
	return 0;
}