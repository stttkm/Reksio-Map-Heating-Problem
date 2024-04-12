//
// Created by Krzysztof Mitko on 12.04.2024.
//

#ifndef REKSIO_MAP_HEATING_PROBLEM_GRAPH_H
#define REKSIO_MAP_HEATING_PROBLEM_GRAPH_H

#include <string>
#include "Node.h"

using namespace std;

class Graph {
public:
    void read(string file_path);

    void reset_heat();

    void display();

    bool check_visibility();

    bool check_perfection();


    vector<Node> nodes;
    int node_num;
};


#endif //REKSIO_MAP_HEATING_PROBLEM_GRAPH_H
