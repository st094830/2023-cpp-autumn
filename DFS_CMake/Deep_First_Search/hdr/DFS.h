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

	

	// Соседи вершины at
	void connectedVertexesCount(int at);

	// Компоненты связности
	void conComponents();

	// Проверка на дерево (включая проверку на циклы)
	bool IsTree();
	bool HasCycles();
	int Connected(int vertex);

	// Поиск мостов в графе
	void bridgeSearch();


	// Компоненты сильной связности
	void strongConComponents();

	// Вывод данных в формате .tex
	void Solve(std::string _graphName);
	
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
	std::string graphName;
	int _timer;
	
	//DFS-s
	void DFS(int at);
	void DFSforConComps(int at, std::vector<int>& component);
	bool DFSforCycles(int vertex);
	void DFSforSCC(int at);
	void DFSforBridges(int at, int parent);
	void DFSforSCCFrontwards(int at);
	void DFSforSCCBackwards(int at);
	std::vector<int> _colors;
	bool* _visited;
	std::vector<int> _disc;
	std::vector<int> _low;


	// Solves
	std::vector<std::vector<int>> _conComponents;
	std::vector<SEdge> _bridges;
	std::vector<std::vector<int>> _SCC;
	
	// SCC Kosaraju algthm preparations
	std::vector<bool> _inStack;
	std::vector<int> _forwardStack;
	std::vector<int> _sConComp;
	std::vector<std::vector<int>> reverseGraph;

};

#endif