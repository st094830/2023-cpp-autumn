#include "LatexGenerator.h"

LatexGenerator::LatexGenerator(const std::string _pathName) : directory(_pathName)
{
	std::filesystem::path dataDir = directory / "data";
	std::filesystem::remove_all(dataDir);
	std::filesystem::create_directories(dataDir);
}

std::filesystem::path LatexGenerator::createDirectory() 
{
	std::filesystem::path localDir = directory / "data" / "LaTeX_material";
	std::filesystem::create_directories(localDir);
	return localDir;
}


void LatexGenerator::DataWriterMatrix(const std::vector<std::vector<int>> _matrix)
{
	std::filesystem::path localDir = createDirectory();
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
	std::filesystem::path localDir = createDirectory();
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

void LatexGenerator::DataWriterIsTree(const std::vector<std::vector<int>> _matrix, bool isTree) 
{
	std::filesystem::path localDir = createDirectory();
	std::ofstream latexCode(localDir / "Tree.tex");
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

void LatexGenerator::DataWriterBridges(std::vector<SEdge> _bridges)
{
	std::filesystem::path localDir = createDirectory();
	std::ofstream latexCode(localDir / "Bridges_list.tex");
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
	std::filesystem::path localDir = createDirectory();
	std::ofstream latexCode(localDir / "SCC.tex");
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

