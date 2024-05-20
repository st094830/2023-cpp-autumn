#pragma once
#ifndef _LATEXGEN_
#define _LATEXGEN_
#include <filesystem>
#include <string>
#include <vector>
#include <fstream>
#include "DFS.h"

struct LatexGenerator
{
public:
	LatexGenerator() {};
	LatexGenerator(const std::string _pathName, std::string graphName);
	std::filesystem::path LatexGenerator::createDir();
	void DataWriterMatrix(const std::vector<std::vector<int>> _matrix);
	void DataWriterAdjacency(const std::vector<std::vector<int>> _adjacency);
	void DataWriterConCom(const std::vector<std::vector<int>> _conComponents);
	void DataWriterIsTree(bool isTree);
	void DataWriterBridges(const std::vector<SEdge> _bridges);
	void DataWriterSSC(const std::vector<std::vector<int>> _SCC);
private:
	std::filesystem::path directory;
	std::string graphName;
};


#endif