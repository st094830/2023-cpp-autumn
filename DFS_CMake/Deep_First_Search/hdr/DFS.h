#pragma once
#ifndef _DFS_
#define _DFS_

#include <vector>
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

	// Компоненты связности
	void conComponents();

	// Проверка на дерево (включая проверку на циклы)
	bool HasCycles(int current, int source);
	bool IsTree();

	// Поиск мостов в графе
	void bridgeSearch();


	// Компоненты сильной связности
	void strongConComponents();

	// Вывод данных в формате .tex
	void Solve();
	
	void SolveMatrix();
	void SolveAdjacency();
	void SolveTreeCheck();
	void SolveConComponents();
	void SolveBridgeCheck();
	void SolveStrongCC();
	
private:
	int getVertexesCountFromEdges();
	void dispose();
	void disposeMatrix();
	void disposeEdges();
	std::vector<SEdge> _edgesList;
	std::vector<std::vector<int>> _matrix;
	std::vector<std::vector<int>> _adjacency;
	int _vertexes;
	int _edges;
	SEdge* _edge;
	
	//DFS-s
	void DFSforConComps(int at, std::vector<int>& component);
	void DFSforBridges(int at, int parent, std::vector<bool>& visitedVertices, std::vector<int>& disc, std::vector<int>& low);
	void DFSforSCC(int at, int vertcount);
	bool* _visited;


	// Solves
	std::vector<std::vector<int>> _conComponents;
	std::vector<SEdge> _bridges;
	std::vector<std::vector<int>> _SCC;
	
	// SCC Tarjan algthm preparations
	int timer = 0;
	std::vector<int> time;
	std::vector<int> stack;
	std::vector<int> lowlink;
	std::vector<int> color;
	int vertcount = 0;

};

#endif