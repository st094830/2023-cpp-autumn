#pragma once
#ifndef _LATEXGEN_
#define _LATEXGEN_
#include <filesystem>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <DFS.h>

struct LatexGenerator
{
public:
	LatexGenerator() {};
	LatexGenerator(const std::string _pathName);
	std::filesystem::path createDirectory();
	void DataWriterMatrix(const std::vector<std::vector<int>> _matrix);
	void DataWriterAdjacency(const std::vector<std::vector<int>> _adjacency);
	void DataWriterIsTree(const std::vector<std::vector<int>> Matrix, bool isTree);
	void DataWriterBridges(const std::vector<SEdge> _bridges);
	void DataWriterSSC(const std::vector<std::vector<int>> _SCC);
private:
	std::filesystem::path directory;
};


#endif