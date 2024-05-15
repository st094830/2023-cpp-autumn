#pragma once
#ifndef _DFS_
#define _DFS_

#include <vector>
#include <stdio.h>
#include "SEdge.h"
#include "LatexGenerator.h"
#include "GraphReader.h"

class CGraph 
{
public:
	CGraph():  _vertexes(0), _edges(0) {} 
	CGraph(int vertexes, int edges) : _vertexes(vertexes), _edges(edges) {}
	~CGraph() { dispose(); }
	
	// Считывание графа из файла и инициализация матрицы и списка смежности
	void initMatrix();
	void initEdges();
	void init();
	void initMatrixFromEdges();
	void initAdjacencyList();

	// Поиск в глубину
	void DFSprep(int target);
	void DFS(int at);

	// Соседи вершины at
	void connectedVertexesCount(int at);

	// Проверка на дерево (включая проверку на циклы)
	bool HasCycles(int current, int source);
	bool IsTree();

	// Поиск мостов в графе
	void bridgeSearch();


	// Компоненты сильной связности
	void strongConComponents();

	// Вывод данных в формате .tex
	void Solve(std::string function);
	
	
private:
	int getVertexesCountFromEdges();

	void DFSforConComps(int at, std::vector<int>& component);
	void DFSforBridges(int at, int parent, std::vector<bool>& visitedVertices, std::vector<int>& disc, std::vector<int>& low);
	void DFSforSCC(int at, int vertcount);
	//
	std::vector<std::vector<int>> _conComponents;
	void dispose();
	void disposeMatrix();
	void disposeEdges();

	std::vector<SEdge> _edgesList;
	std::vector<std::vector<int>> _adjacency;
	std::vector<std::vector<int>> _matrix;
	int _vertexes;
	int _edges;
	
	bool* _visited;
	SEdge* _edge;
	std::vector<SEdge> _bridges;
	int timer = 0;
	std::vector<std::vector<int>> _SCC;


	std::vector<int> time;
	std::vector<int> stack;
	std::vector<int> lowlink;
	std::vector<int> color;
	int vertcount = 0;

};

#endif