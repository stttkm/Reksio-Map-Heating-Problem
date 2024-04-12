//
// Created by Krzysztof Mitko on 12.04.2024.
//

#ifndef REKSIO_MAP_HEATING_PROBLEM_NODE_H
#define REKSIO_MAP_HEATING_PROBLEM_NODE_H

#include <vector>

using namespace std;

class Node {
public:
    Node();
    void heat();
    void heat_a_little();
    void reset_heat(); // heat_status=0
    bool is_perfect(); //2h -> heat_status=4
    bool is_almost_burnt_out(); //2.5h -> heat_status=5
    bool is_burnt_out(); //3h -> heat_status=6
    vector<Node *> neighbors;
    int id;

private:
    int heat_status = 0; //let's multiply by 2 the heat unit introduced in readme to use int instead of float

};


#endif //REKSIO_MAP_HEATING_PROBLEM_NODE_H
