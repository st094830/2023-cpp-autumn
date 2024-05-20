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

void CGraph::initAdjacencyList()
{
	_adjacency.resize(_vertexes);
	for (int i = 0; i < _vertexes; ++i)
	{
		for (int j = 0; j < _vertexes; ++j)
		{
			if (_matrix[i][j] != 0)
			{
				_adjacency[i].push_back(j);
			}
		}
	}
}


void CGraph::Solve(std::string _graphName)  
{
	initEdges();
	initMatrixFromEdges();
	initAdjacencyList();
	this->graphName = _graphName;
}
void CGraph::SolveMatrix()
{
	LatexGenerator latex("Results", graphName);
	latex.DataWriterMatrix(_matrix);
}
void CGraph::SolveAdjacency()
{
	LatexGenerator latex("Results", graphName);
	latex.DataWriterAdjacency(_adjacency);
}
void CGraph::SolveTreeCheck()
{
	LatexGenerator latex("Results", graphName);
	latex.DataWriterIsTree(IsTree());
}
void CGraph::SolveConComponents()
{
	LatexGenerator latex("Results", graphName);
	conComponents();
	latex.DataWriterConCom(_conComponents);
}
void CGraph::SolveBridgeCheck()
{
	LatexGenerator latex("Results", graphName);
	bridgeSearch();
	latex.DataWriterBridges(_bridges);
}
void CGraph::SolveStrongCC()
{
	LatexGenerator latex("Results", graphName);
	strongConComponents();
	latex.DataWriterSSC(_SCC);
}




void CGraph::DFS(int at)
{
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
	_visited = new bool [_vertexes] {false};
	DFS(at - 1);
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


int CGraph::Connected(int vertex)
{
	int visVertxs = 1;
	_visited[vertex] = true;
	for (int i = 0; i < _adjacency[vertex].size(); ++i)
	{
		if (!_visited[_adjacency[vertex][i]])
		{
			visVertxs += Connected(_adjacency[vertex][i]);
		}
	}
	return visVertxs;
}

bool CGraph::HasCycles()
{
	for (int i = 0; i < _vertexes; ++i)
	{
		if (!_visited[i] && DFSforCycles(i))
		{
			return true;
		}
	}
	_visited = new bool[_vertexes] {false};
	return false;
}

bool CGraph::DFSforCycles(int vertex)
{
	if (!_visited[vertex]) 
	{
		_colors[vertex] = 1;
		_visited[vertex] = true;
		for (int j = 0; j < _adjacency[vertex].size(); ++j)
		{
			if (!_visited[_adjacency[vertex][j]] && DFSforCycles(_adjacency[vertex][j]))
			{
				return true;
			}
			else if (_colors[_adjacency[vertex][j]] == 1)
			{
				return true;
			}
		}
		_colors[vertex] = 2;
		return false;
	}
}

bool CGraph::IsTree() 
{
	
	_colors.resize(_vertexes, 0);
	_visited = new bool[_vertexes] {false};
	return (!HasCycles() && (Connected(0) == _vertexes));
}




void CGraph::conComponents()
{
	_visited = new bool[_vertexes] {false};
	std::vector<int> component;
	for (int i = 0; i < _vertexes; ++i)
	{
		if (!_visited[i])
		{
			component.clear();
			DFSforConComps(i, component);
			_conComponents.push_back(component);
		}
	}
}

void CGraph::DFSforConComps(int at, std::vector<int>& component) 
{

	_visited[at] = true;
	component.push_back(at);
	for (int j = 0; j < _adjacency[at].size(); ++j) 
	{
		if (!_visited[_adjacency[at][j]])
		{
			DFSforConComps(_adjacency[at][j], component);
		}
	}
}

void CGraph::bridgeSearch() 
{
	_visited = new bool[_vertexes] {false};
	_disc.resize(_vertexes, -1);
	_low.resize(_vertexes, -1);
	_timer = 0;
	for (int i = 0; i < _vertexes; i++) 
	{
		if (!_visited[i]) 
		{
			DFSforBridges(i, -1);
		}
	}
	_disc.clear();
	_low.clear();
}

void CGraph::DFSforBridges(int at, int parent)
{
	_visited[at] = true;
	++_timer;
	_disc[at] = _timer;
	_low[at] = _timer;

	for (int i = 0; i < _adjacency[at].size(); ++i) 
	{
		if (_adjacency[at][i] == parent)
		{
			continue;
		}
		if (_visited[_adjacency[at][i]]) 
		{
			_low[at] = std::min(_low[at], _disc[_adjacency[at][i]]);
		}
		else 
		{
			DFSforBridges(_adjacency[at][i], at);
			_low[at] = std::min(_low[at], _low[_adjacency[at][i]]);
			if (_low[_adjacency[at][i]] > _disc[at]) 
			{
				_bridges.push_back({ at, _adjacency[at][i], 1 });
			}
		}
	}
}


void CGraph::strongConComponents()
{
	_inStack.resize(_vertexes, false);
	_forwardStack.clear();
	_visited = new bool[_vertexes] {false};
	for (int i = 0; i < _vertexes; ++i)
	{
		if (!_visited[i])
		{
			DFSforSCCFrontwards(i);
		}
	}

	reverseGraph.clear();
	reverseGraph.resize(_vertexes);
	for (int i = 0; i < _vertexes; ++i)
	{
		for (int j = 0; j < _adjacency[i].size(); ++j)
		{
			reverseGraph[_adjacency[i][j]].push_back(i);
		}
	}

	_sConComp.clear();
	_visited = new bool[_vertexes] {false};
	while (!_forwardStack.empty())
	{
		int vertex = 0;
		vertex = _forwardStack.back();
		_forwardStack.pop_back();
		if (!_visited[vertex])
		{
			DFSforSCCBackwards(vertex);
			_SCC.push_back(_sConComp);
			_sConComp.clear();
		}
	}

	delete[] _visited;
}

void CGraph::DFSforSCCFrontwards(int at)
{
	_visited[at] = true;
	for (int i = 0; i < _adjacency[at].size(); ++i)
	{
		int neighbor = _adjacency[at][i];
		if (!_visited[neighbor])
		{
			DFSforSCCFrontwards(neighbor);
		}
	}
	_forwardStack.push_back(at);
}

void CGraph::DFSforSCCBackwards(int at)
{
	_visited[at] = true;
	_sConComp.push_back(at);
	for (int i = 0; i < reverseGraph[at].size(); ++i)
	{
		int neighbor = reverseGraph[at][i];
		if (!_visited[neighbor])
		{
			DFSforSCCBackwards(neighbor);
		}
	}
}