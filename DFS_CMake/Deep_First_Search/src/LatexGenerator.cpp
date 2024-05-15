#include "LatexGenerator.h"

LatexGenerator::LatexGenerator(const std::string _pathName) : directory(_pathName)
{
	std::filesystem::path dataDir = directory;
	std::filesystem::create_directories(dataDir);
}


void LatexGenerator::DataWriterMatrix(const std::vector<std::vector<int>> _matrix)
{
	std::ofstream latexCode(directory / "Matrix.tex");
	latexCode << "\\documentclass{article}\n";
	latexCode << "\\usepackage{amsmath}\n";
	latexCode << "\\usepackage[russian]{babel}\n";
	latexCode << "\\begin{document}\n\n";
	latexCode << "\nMatrix: \n";
	for (size_t i = 0; i < _matrix.size(); ++i)
	{
		for (size_t j = 0; j < _matrix[i].size(); ++j)
		{
			latexCode << std::to_string(_matrix[i][j]);
			if (j < (_matrix[i].size() - 1))
			{
				latexCode << " ";
			}
		}
		latexCode << "\n";
	}
	latexCode << "\n";
	latexCode << "\\end{document}";
}
void LatexGenerator::DataWriterAdjacency(const std::vector<std::vector<int>> _adjacency)
{
	std::ofstream latexCode(directory / "Adjacency_List.tex");
	latexCode << "\\documentclass{article}\n";
	latexCode << "\\usepackage{amsmath}\n";
	latexCode << "\\usepackage[russian]{babel}\n";
	latexCode << "\\begin{document}\n\n";
	latexCode << "Adjacency list: \n";
	for (size_t i = 0; i < _adjacency.size(); ++i) 
	{
		latexCode << std::to_string(i) << ": ";
		for (size_t j = 0; j < _adjacency[i].size(); ++j)
		{
			latexCode << std::to_string(_adjacency[i][j]);
			if (j < (_adjacency[i].size() - 1))
			{
				latexCode << ", ";
			}
		}
		latexCode << "\n";
	}
	latexCode << "\n";
	latexCode << "\\end{document}";
}

void LatexGenerator::DataWriterIsTree(const std::vector<std::vector<int>> _matrix, bool isTree) 
{
	std::ofstream latexCode(directory / "Tree.tex");
	latexCode << "\\documentclass{article}\n";
	latexCode << "\\usepackage{amsmath}\n";
	latexCode << "\\usepackage[russian]{babel}\n";
	latexCode << "\\begin{document}\n\n";

	latexCode << "\nMatrix\n";
	for (size_t i = 0; i < _matrix.size(); ++i)
	{
		for (size_t j = 0; j < _matrix[i].size(); ++j)
		{
			latexCode << std::to_string(_matrix[i][j]);
			if (j < (_matrix[i].size() - 1))
			{
				latexCode << " ";
			}
		}
		latexCode << "\n";
	}
	latexCode << (isTree ? "is a tree" : "is not a tree")<<"\n\n";
	latexCode << "\\end{document}";

}


void LatexGenerator::DataWriterConCom(std::vector<std::vector<int>> _conComponents)
{
	std::ofstream latexCode(directory / "Connected_components.tex");
	latexCode << "\\documentclass{article}\n";
	latexCode << "\\usepackage{amsmath}\n";
	latexCode << "\\usepackage[russian]{babel}\n";
	latexCode << "\\begin{document}\n\n";
	if (_conComponents.size() > 0) {
		latexCode << "List of connected components:\n";
		for (size_t i = 0; i < _conComponents.size(); ++i)
		{
			for (size_t j = 0; j < _conComponents[i].size(); ++j)
			{
				latexCode << std::to_string(_conComponents[i][j]);
				if (j < (_conComponents[i].size() - 1))
				{
					latexCode << " ";
				}
			}
			latexCode << "\n";
		}
	}
	else 
	{
		latexCode << "No connectivity components can be found\n\n";
	}
	
	latexCode << "\\end{document}";
}


void LatexGenerator::DataWriterBridges(std::vector<SEdge> _bridges)
{
	std::ofstream latexCode(directory / "Bridges_list.tex");
	latexCode << "\\documentclass{article}\n";
	latexCode << "\\usepackage{amsmath}\n";
	latexCode << "\\usepackage[russian]{babel}\n";
	latexCode << "\\begin{document}\n\n";
	if (_bridges.size() > 0) {
		latexCode << "\nList of bridges:\n\n";
		for (size_t i = 0; i < _bridges.size(); ++i)
		{
			latexCode << std::to_string(_bridges[i].a) << " " << std::to_string(_bridges[i].a) << "\n\n";
		}
	}
	else 
	{
		latexCode << "No bridges found" << "\n\n";
	}
	
	latexCode << "\\end{document}";
}

void LatexGenerator::DataWriterSSC(std::vector<std::vector<int>> _SCC)
{
	std::ofstream latexCode(directory / "SCC.tex");
	latexCode << "\\documentclass{article}\n";
	latexCode << "\\usepackage{amsmath}\n";
	latexCode << "\\usepackage[russian]{babel}\n";
	latexCode << "\\begin{document}\n\n";

	if (_SCC.size() > 0) {
		latexCode << "\nList of strong connectivity components:\n";
		for (size_t i = 0; i < _SCC.size(); ++i)
		{
			for (size_t j = 0; j < (_SCC[i]).size(); ++j)
			{
				latexCode << std::to_string(_SCC[i][j]);
				if (j < (_SCC[i].size() - 1))
				{
					latexCode << " ";
				}
			}
			latexCode << "\n\n";
		}
	}
	else 
	{
		latexCode << "No strong connectivity components can be found" << "\n\n";
	}
	
	latexCode << "\\end{document}";
}

