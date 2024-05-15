#pragma once
#ifndef _DATAREAD_
#define _DATAREAD_

#include <filesystem>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <DFS.h>

struct GraphReader {
public:
    GraphReader(std::string filename) : filename(filename) {};
    std::vector<SEdge> readEdges();
private:
    std::string filename;
    std::vector<SEdge> edges;
};

#endif