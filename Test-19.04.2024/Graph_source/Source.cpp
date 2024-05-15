#include "Header.h"

CGraph::CGraph()
	: _vertexes(0), _edges(0), _matrix(nullptr), _edge(nullptr) {}

CGraph::CGraph(int vertexes, int edges)
	: _vertexes(vertexes), _edges(edges), _matrix(nullptr), _edge(nullptr)
{
	init();
}

CGraph::~CGraph()
{
	dispose();
}

void CGraph::PrintMatrix()
{
	if (_matrix == nullptr)
	{
		if (_edge == nullptr)
		{
			std::cout << "Graph empty" << std::endl;
			return;
		}
		initMatrixFromEdges();
	}
	for (int i = 1; i < _vertexes; ++i)
	{
		for (int j = 1; j < _vertexes; ++j)
		{
			std::cout << _matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void CGraph::PrintEdges()
{
	if (_edge == nullptr)
	{
		if (_matrix == nullptr)
		{
			std::cout << "Graph empty" << std::endl;
			return;
		}
		initEdgesFromMatrix();
	}
	for (int i = 0; i < _edges; ++i)
	{
		std::cout << _edge[i] << std::endl;
	}
}

void CGraph::ReadMatrix(int vertexes)
{
	_vertexes = vertexes;
	initMatrix();
	for (int i = 0; i < _vertexes; ++i)
	{
		for (int j = 0; j < _vertexes; ++j)
		{
			std::cin >> _matrix[i][j];
		}
	}
}

void CGraph::ReadEdges(int edges, bool haveweight)
{
	_edges = edges;
	initEdges();
	for (int i = 0; i < _edges; ++i)
	{
		std::cin >> _edge[i].a >> _edge[i].b;
		if (haveweight)
		{
			std::cin >> _edge[i].w;
		}
	}
}

void CGraph::init()
{
	dispose();
	initMatrix();
	initEdges();
}

void CGraph::initMatrix()
{
	if (_vertexes == 0)
	{
		return;
	}
	_matrix = new int* [_vertexes];
	for (int i = 0; i < _vertexes; ++i)
	{
		_matrix[i] = new int[_vertexes] { 0 };
	}
}

void CGraph::initEdges()
{
	if (_edges == 0)
	{
		return;
	}
	_edge = new SEdge[_edges];
}

void CGraph::initMatrixFromEdges()
{
	disposeMatrix();
	_vertexes = getVertexesCountFromEdges();
	initMatrix();
	for (int i = 0; i < _edges; ++i)
	{
		_matrix[_edge[i].a][_edge[i].b] = _edge[i].w;
	}
}

int CGraph::getEdgesCountFromMatrix()
{
	int count = 0;
	for (int i = 0; i < _vertexes; ++i)
	{
		for (int j = 0; j < _vertexes; ++j)
		{
			count += (_matrix[i][j] != 0);
		}
	}
	return count;
}

void CGraph::dispose()
{
	disposeMatrix();
	disposeEdges();
}

void CGraph::disposeMatrix()
{
	if (_matrix != nullptr)
	{
		for (int i = 0; i < _vertexes; ++i)
		{
			delete[] _matrix[i];
		}
		delete[] _matrix;
		_matrix = nullptr;
	}
}

void CGraph::disposeEdges()
{
	if (_edge != nullptr)
	{
		delete[] _edge;
		_edge = nullptr;
	}
}

void CGraph::initEdgesFromMatrix()
{
	disposeEdges();
	_edges = getEdgesCountFromMatrix();
	initEdges();
	for (int i = 0, k = 0; i < _vertexes && k < _edges; ++i)
	{
		for (int j = 0; j < _vertexes && k < _edges; ++j)
		{
			if (_matrix[i][j] != 0)
			{
				_edge[k++].set(i + 1, j + 1, _matrix[i][j]);
			}
		}
	}
}


int CGraph::getVertexesCountFromEdges()
{
	int res = 0;
	for (int i = 0; i < _edges; ++i)
	{
		res = (res > _edge[i].a ? res : _edge[i].a);
		res = (res > _edge[i].b ? res : _edge[i].b);
	}
	return res + 1;
}

std::ostream& operator<<(std::ostream& stream, const SEdge& edge)
{
	stream << edge.a << " " << edge.b;
	if (edge.w > 1)
	{
		stream << " " << edge.w;
	}
	return stream;
}

void CGraph::inputAdjencyList()
{
	std::cin >> _vertexes;
	for (int i = 1; i <= _vertexes; ++i)
	{
		int edges = 0;
		std::cin >> edges;
		for (int j = 0; j < edges; ++j)
		{
			int end = 0;
			std::cin >> end;
			_matrix[i][end] = 1;
		}
	}
}

void CGraph::outputAdjencyList()
{
	std::cout << _vertexes << std::endl;
	for (int i = 1; i <= _vertexes; ++i)
	{
		int count = 0;
		for (int j = 1; j <= _vertexes; ++j)
		{
			count += _matrix[i][j];
		}
		std::cout << count << " ";
		for (int j = 1; j <= _vertexes; ++j)
		{
			if (_matrix[i][j] == 1)
			{
				std::cout << j << " ";
			}
		}
		std::cout << std::endl;
	}
}

void CGraph::initPowers()
{
	_powers = new int [_vertexes] { 0 };
	for (int i = 1; i <= _vertexes; ++i)
	{
		for (int j = 1; j <= _vertexes; ++j)
		{
			_powers[i] += _matrix[i][j];
		}
	}
}
void CGraph::outputPowers()
{
	initPowers();
	for (int i = 1; i <= _vertexes; ++i)
	{
		std::cout << _powers[i] << " ";
	}
	std::cout << std::endl;
}

bool CGraph::isRegular()
{
	initPowers();
	for (int i = 1; i <= _vertexes; ++i)
	{
		if (_powers[i] != _powers[1])
		{
			return false;
		}
	}
	return true;
}

bool CGraph::isOriented()
{
	bool res = false;
	for (int i = 1; i <= _vertexes; ++i)
	{
		if (_matrix[i][i] == 1)
		{
			return false;
		}
		for (int j = 1; j <= _vertexes; ++j)
		{
			if (_matrix[i][j] != _matrix[j][i])
			{
				res = true;
			}
		}
	}
	return res;
}

void CGraph::printOrigins()
{
	_origin = new bool [_vertexes] { 0 };
	int count = 0;
	for (int i = 1; i <= _vertexes; ++i)
	{
		_origin[i] = true;
		for (int j = 1; j <= _vertexes; ++j)
		{
			_origin[i] &= _matrix[i][j] == 0;
		}
		count += (int)_origin[i];
	}
	std::cout << count << " ";
	for (int i = 1; i <= _vertexes; ++i)
	{
		if (_origin[i])
		{
			std::cout << i << " ";
		}
	}
	std::cout << std::endl;
}

void CGraph::printDrains()
{
	_drain = new bool[_vertexes] { 0 };
	int count = 0;
	for (int i = 1; i <= _vertexes; ++i)
	{
		_drain[i] = true;
		for (int j = 1; j <= _vertexes; ++j)
		{
			_drain[i] &= _matrix[i][j] == 0;
		}
		count += (int)_drain[i];
	}
	std::cout << count << " ";
	for (int i = 1; i <= _vertexes; ++i)
	{
		if (_drain[i])
		{
			std::cout << i << " ";
		}
	}
	std::cout << std::endl;
}

bool CGraph::isFull()
{

}
bool CGraph::isTournament()
{

}