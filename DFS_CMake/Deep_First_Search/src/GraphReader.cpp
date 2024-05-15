#include "GraphReader.h"

std::vector<SEdge> GraphReader::readEdges() {

    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            std::istringstream iss(line);
            int start;
            int end;
            int weight;
            char ch;

            iss >> start >> end >> weight;
            edges.push_back({ start - 1, end - 1, weight });
        }
        file.close();
    }
    else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
    return edges;
}