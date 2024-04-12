//
// Created by Krzysztof Mitko on 12.04.2024.
//

#include "Node.h"

Node::Node() {
    this->heat_status = 0;
    this->neighbors = vector<Node *>();
    this->id = -1;
}

void Node::heat() {
    this->heat_status = min(6, this->heat_status + 2);
    for (Node* neighbor: this->neighbors) {
        neighbor->heat_a_little();
    }
}

void Node::heat_a_little() {
    this->heat_status = min(6, this->heat_status + 1);
}

void Node::reset_heat() {
    this->heat_status = 0;
}

bool Node::is_visible() {
    return heat_status == 4 || heat_status == 5;
}

bool Node::is_almost_burnt_out() {
    return heat_status == 5;
}
