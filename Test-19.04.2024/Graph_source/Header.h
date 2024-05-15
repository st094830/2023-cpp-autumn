#pragma once
#include <iostream>

struct SEdge {
	int a;
	int b;
	int w;
	SEdge(int a = 0, int b = 0, int w = 1) : a(a), b(b), w(w) {}
	SEdge(const SEdge& src) : a(src.a), b(src.b), w(src.w) {}
	~SEdge() {}
	void set(int a, int b, int w)
	{
		this->a = a;
		this->b = b;
		this->w = w;
	}
	friend std::ostream& operator<<(std::ostream& stream, const SEdge& edge);
};

class CGraph {
public:
	CGraph();
	CGraph(int vertexes, int edges);
	~CGraph();
	///выводит матрицу смежности графа
	void PrintMatrix();
	///выводит дуги графа
	void PrintEdges();
	///считывает матрицу смежности графа
	void ReadMatrix(int vertexes);
	///считывает дуги графа
	void ReadEdges(int edges, bool haveweight = false);

private:

	void init();

	void initMatrix();

	void initEdges();
	void initMatrixFromEdges();
	void initEdgesFromMatrix();
	void initPowers();
	int getVertexesCountFromEdges();
	int getEdgesCountFromMatrix();
	void inputAdjencyList();
	void outputAdjencyList();
	void outputPowers();
	bool isRegular();
	bool isOriented();
	bool isFull();
	void printOrigins();
	void printDrains();
	bool isTournament();
	void dispose();

	void disposeMatrix();

	void disposeEdges();

	int _vertexes;
	int _edges;
	int** _matrix;
	int* _powers;
	bool* _origin;
	bool* _drain;
	SEdge* _edge;
};
