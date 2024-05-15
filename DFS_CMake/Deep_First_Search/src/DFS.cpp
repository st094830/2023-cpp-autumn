#include <iostream>
#include "DFS.h"



void CGraph::init()
{
	dispose();
	initMatrix();
}

void CGraph::initMatrix()
{
	_matrix.resize(_vertexes);
	for (int i = 0; i < _vertexes; ++i)
	{
		for (int j = 0; j < _vertexes; ++j) 
		{
			_matrix[i].push_back(0);
		}
	}
}

void CGraph::initEdges() 
{
	GraphReader reader("C:\\Users\\ASUS\\source\\repos\\2023-cpp-autumn\\DFS_CMake\\Deep_First_Search\\example\\example.txt");
	_edgesList = reader.readEdges();
}


void CGraph::dispose()
{
	disposeMatrix();
}

void CGraph::disposeMatrix()
{
	_matrix.clear();
}


void CGraph::disposeEdges() 
{
	_edgesList.clear();
}

int CGraph::getVertexesCountFromEdges()
{
	int res = 0;
	for (int i = 0; i < _edgesList.size(); ++i)
	{
		res = (res > _edgesList[i].a ? res : _edgesList[i].a);
		res = (res > _edgesList[i].b ? res : _edgesList[i].b);
	}
	return res + 1;
}

void CGraph::initMatrixFromEdges() 
{
	disposeMatrix();
	_vertexes = getVertexesCountFromEdges();
	initMatrix();
	for (int i = 0; i < _edgesList.size(); ++i)
	{
		_matrix[_edgesList[i].a][_edgesList[i].b] = _edgesList[i].w;
	}
}



void CGraph::DFSprep(int target)
{
	_visited = new bool [_vertexes] {false};
	DFS(target);

}

void CGraph::DFS(int at)
{
	if (_visited[at])
	{
		return;
	}
	_visited[at] = true;
	for (int i = 0; i < _vertexes; ++i)
	{
		if (!_visited[i] && _matrix[at][i])
		{
			DFS(i);
		}
	}
}

void CGraph::connectedVertexesCount(int at) 
{
	DFSprep(at - 1);
	int count = 0;
	for (int i = 0; i < _vertexes; ++i) 
	{
		if (_visited[i]) 
		{
			++count;
		}
	}
	std::cout << count - 1 << std::endl;
}

void CGraph::Solve()  
{
	LatexGenerator latex("Results");
	initEdges();
	initMatrixFromEdges();
	initAdjacencyList();
}
void CGraph::SolveMatrix()
{
	LatexGenerator latex("Results");
	latex.DataWriterMatrix(_matrix);
}
void CGraph::SolveAdjacency()
{
	LatexGenerator latex("Results");
	latex.DataWriterAdjacency(_adjacency);
}
void CGraph::SolveTreeCheck()
{
	LatexGenerator latex("Results");
	latex.DataWriterIsTree(_matrix, IsTree());
}
void CGraph::SolveConComponents()
{
	LatexGenerator latex("Results");
	latex.DataWriterConCom(_conComponents);
}
void CGraph::SolveBridgeCheck()
{
	LatexGenerator latex("Results");
	bridgeSearch();
	latex.DataWriterBridges(_bridges);
}
void CGraph::SolveStrongCC()
{
	LatexGenerator latex("Results");
	strongConComponents();
	latex.DataWriterSSC(_SCC);
}


void CGraph::initAdjacencyList() 
{
	_adjacency.resize(_vertexes);
	for (int i = 0; i < _vertexes; ++i) 
	{
		for (int j = 0; j < _vertexes; ++j) 
		{
			if (_matrix[i][j]!=0) 
			{
				_adjacency[i].push_back(j);
			}
		}
	}
}


bool CGraph::HasCycles(int current, int source) 
{
	if (_visited[current]) 
	{
		return true;
	}
	_visited[current] = true;
	for (int i = 0; i < _vertexes; ++i) 
	{
		if (_visited[i] && _matrix[current][i]) 
		{
			if (HasCycles(i, current)) 
			{
				return true;
			}
		} 
		else if (i != source) 
		{
			return true;
		}
	}
	return false;
}

bool CGraph::IsTree() 
{
	_visited = new bool[_vertexes] {false};
	DFSprep(0);
	for (int i = 0; i < _vertexes; ++i) 
	{
		if (!_visited[i]) 
		{
			delete[] _visited;
			return false;
		}
	}
	delete[] _visited;

	_visited = new bool[_vertexes] {false};
	if (HasCycles(0, -1)) 
	{
		delete[] _visited;
		return false;
	}
	delete[] _visited;
	return true;
}

void CGraph::conComponents()
{
	for (int i = 0; i < _vertexes; ++i)
	{
		if (!_visited[i])
		{
			std::vector<int> component;
			_visited = new bool[_vertexes] {false};
			DFSforConComps(i, component);
			_conComponents.push_back(component);
		}
	}
}

void CGraph::DFSforConComps(int at, std::vector<int>& component) 
{
	if (_visited[at]) 
	{
		return;
	}
	_visited[at] = true;
	component.push_back(at);
	for (int j = 0; j < _vertexes; ++j) 
	{
		if (_matrix[at][j] && !_visited[j]) 
		{
			DFSforConComps(j, component);
		}
	}
}

void CGraph::bridgeSearch() 
{
	std::vector<bool> visitedVertices(_vertexes, false);
	std::vector<int> disc(_vertexes, -1);
	std::vector<int> low(_vertexes, -1);
	
	DFSforBridges(0, -1, visitedVertices, disc, low);
}

void CGraph::DFSforBridges(int at, int parent, std::vector<bool>& visitedVertices, std::vector<int>& disc, std::vector<int>& low)
{
	visitedVertices[at] = true;
	disc[at] = low[at] = ++timer;

	for (int i = 0; i < _vertexes; ++i) {
		if (_matrix[at][i]) {
			if (!visitedVertices[i]) {
				DFSforBridges(i, at, visitedVertices, disc, low);
				low[at] = std::min(low[at], low[i]);
				if (low[i] > disc[at]) {
					_bridges.push_back(SEdge(at, i, 1)); 
				}
			}
			else if (i != parent) {
				low[at] = std::min(low[at], disc[i]);
			}
		}
	}
}

void CGraph::strongConComponents()
{
	time.resize(_vertexes, 0);
	stack.clear();
	lowlink.resize(_vertexes, 0);
	color.resize(_vertexes, 0);
	int vertcount = 0;
	for (int i = 0; i<_vertexes;++i) 
	{
		if (!time[i])
		{
			DFSforSCC(i, vertcount);
		}
	}
}

void CGraph::DFSforSCC(int at, int vertcount)
{
	color[at] = 1;
	time[at] = vertcount;
	lowlink[at] = vertcount;
	vertcount++;
	stack.push_back(at);
	for (int i = 0; i < _adjacency[at].size(); ++i) 
	{
		if (!color[i])
		{
			DFSforSCC(i, vertcount);
			lowlink[at] = std::min(lowlink[at], lowlink[i]);
		}
		else if (color[i] == 1)
		{
			lowlink[at] = std::min(lowlink[at], time[i]);
		}
	}
	if (lowlink[at] == time[at]) 
	{
		int j = 0;
		std::vector<int> stemp;
		while (j != at) 
		{
			j = stack.back();
			stack.pop_back();
			stemp.push_back(j);
		}
		_SCC.push_back(stemp);
	}
}


