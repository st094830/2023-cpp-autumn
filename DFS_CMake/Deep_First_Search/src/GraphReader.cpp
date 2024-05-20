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

            if (iss >> start >> end)
            {
                edges.push_back({ start - 1, end - 1, 1 });
            }
            else if (iss >> start >> end >> weight)
            {
                edges.push_back({ start - 1, end - 1, weight });
            } 
            else
            {
                std::cerr << "Invalid graph syntax";
                break;
            }
            
        }
        file.close();
    }
    else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
    return edges;
}