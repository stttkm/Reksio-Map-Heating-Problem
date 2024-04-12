//
// Created by Krzysztof Mitko on 12.04.2024.
//

#ifndef REKSIO_MAP_HEATING_PROBLEM_BRUTE_FORCE_H
#define REKSIO_MAP_HEATING_PROBLEM_BRUTE_FORCE_H

#include "vector"
#include "Data Structures/Graph.h"

using namespace std;

class Brute_force {
    vector<vector<int>> perfect_solutions = vector<vector<int>>();
    vector<vector<int>> acceptable_solutions = vector<vector<int>>(); // this excludes the perfect_solutions
    Graph graph;
    vector<vector<int>> search_space = vector<vector<int>>();


public:
    Brute_force(const Graph &graph);

    void run();

    void generateVectors(vector<int> &current, int index);

    void save_output();
};


#endif //REKSIO_MAP_HEATING_PROBLEM_BRUTE_FORCE_H
