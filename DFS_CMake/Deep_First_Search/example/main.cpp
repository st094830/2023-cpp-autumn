#include <iostream>
#include "DFS.h"

int main(int argc, char* argv[])
{
	CGraph graph;
	graph.Solve("FisrtGraph");
	graph.SolveMatrix();
	graph.SolveTreeCheck();
	graph.SolveConComponents();
	graph.SolveBridgeCheck();
	graph.SolveStrongCC();
	return EXIT_SUCCESS;
}