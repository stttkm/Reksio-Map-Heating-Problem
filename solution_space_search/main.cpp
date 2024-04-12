//
// Created by Krzysztof Mitko on 12.04.2024.
//
#include <iostream>
#include "Graph.h"

using namespace std;

int main(){
    Graph graph = Graph();
    graph.read("../test_graphs/Reksio_Graph.json");
    graph.display();
}