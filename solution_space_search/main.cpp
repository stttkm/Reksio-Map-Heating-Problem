//
// Created by Krzysztof Mitko on 12.04.2024.
//
#include <iostream>
#include "Data Structures/Graph.h"
#include "Algorithms/Brute_force.h"

using namespace std;

int main(){
    Graph graph = Graph();
    graph.read("../test_graphs/Reksio_Graph.json");
    graph.display();

    Brute_force brute_force = Brute_force(graph);
    brute_force.run();
}