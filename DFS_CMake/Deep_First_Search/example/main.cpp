#include <iostream>
#include "DFS.h"

int main(int argc, char* argv[])
{
	CGraph graph;
	graph.Solve();
	graph.SolveMatrix();
	graph.SolveStrongCC();
	graph.SolveTreeCheck();
	graph.SolveConComponents();

	return EXIT_SUCCESS;
}