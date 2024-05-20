#include "LatexGenerator.h"

LatexGenerator::LatexGenerator(const std::string _pathName, std::string _graphName) : directory(_pathName), graphName(_graphName)
{
	
	std::filesystem::path dataDir = directory;
	std::filesystem::create_directories(dataDir);
}
std::filesystem::path LatexGenerator::createDir() 
{
	std::filesystem::path localDir = directory / graphName;
	std::filesystem::create_directories(localDir);
	return localDir;
}

void LatexGenerator::DataWriterMatrix(const std::vector<std::vector<int>> _matrix)
{
	std::filesystem::path localDir = createDir();
	std::ofstream latexCode(localDir / "Matrix.tex");
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
	std::filesystem::path localDir = createDir();
	std::ofstream latexCode(localDir / "Adjacency_List.tex");
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

void LatexGenerator::DataWriterIsTree(bool isTree) 
{
	std::filesystem::path localDir = createDir();
	std::ofstream latexCode(localDir / "Tree.tex");
	latexCode << "\\documentclass{article}\n";
	latexCode << "\\usepackage{amsmath}\n";
	latexCode << "\\usepackage[russian]{babel}\n";
	latexCode << "\\begin{document}\n\n";

	latexCode << "\nGiven graph " << (isTree ? "is a tree" : "is not a tree")<<"\n\n";
	latexCode << "\\end{document}";

}


void LatexGenerator::DataWriterConCom(std::vector<std::vector<int>> _conComponents)
{
	std::filesystem::path localDir = createDir();
	std::ofstream latexCode(localDir / "Connected_components.tex");
	latexCode << "\\documentclass{article}\n";
	latexCode << "\\usepackage{amsmath}\n";
	latexCode << "\\usepackage[russian]{babel}\n";
	latexCode << "\\begin{document}\n\n";
	if (_conComponents.size() > 0) {
		int counter = 1;
		latexCode << "List of connected components:\n\n";
		for (size_t i = 0; i < _conComponents.size(); ++i)
		{
			latexCode << "Connected component " << std::to_string(counter) << ": \n\n";
			counter++;
			for (size_t j = 0; j < _conComponents[i].size(); ++j)
			{
				latexCode << std::to_string(_conComponents[i][j] + 1);
				if (j < (_conComponents[i].size() - 1))
				{
					latexCode << " ";
				}
			}
			latexCode << "\n\n";
		}
	}
	else 
	{
		latexCode << "No connected components can be found\n\n";
	}
	
	latexCode << "\\end{document}";
}


void LatexGenerator::DataWriterBridges(std::vector<SEdge> _bridges)
{
	std::filesystem::path localDir = createDir();
	std::ofstream latexCode(localDir / "Bridges_list.tex");
	latexCode << "\\documentclass{article}\n";
	latexCode << "\\usepackage{amsmath}\n";
	latexCode << "\\usepackage[russian]{babel}\n";
	latexCode << "\\begin{document}\n\n";
	if (_bridges.size() > 0) {
		latexCode << "\nList of bridges:\n\n";
		for (size_t i = 0; i < _bridges.size(); ++i)
		{
			latexCode << std::to_string(_bridges[i].a + 1) << " " << std::to_string(_bridges[i].b + 1) << "\n\n";
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
	std::filesystem::path localDir = createDir();
	std::ofstream latexCode(localDir / "SCC.tex");
	latexCode << "\\documentclass{article}\n";
	latexCode << "\\usepackage{amsmath}\n";
	latexCode << "\\usepackage[russian]{babel}\n";
	latexCode << "\\begin{document}\n\n";

	if (_SCC.size() > 0) {
		latexCode << "\nList of strongly connected components:\n\n";
		for (size_t i = 0; i < _SCC.size(); ++i)
		{ 
			latexCode << "Strongly connected component " << std::to_string(i + 1) << ":\n\n";
			for (size_t j = 0; j < (_SCC[i]).size(); ++j)
			{
				latexCode << std::to_string(_SCC[i][j] + 1);
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
		latexCode << "No strongly connected components can be found" << "\n\n";
	}
	
	latexCode << "\\end{document}";
}

