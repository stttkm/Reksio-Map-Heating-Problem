//
// Created by Krzysztof Mitko on 12.04.2024.
//

#include "Graph.h"
#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include <cstdio>
#include <vector>
#include <iostream>

void Graph::read(string file_path) {
    FILE *fp = fopen(file_path.c_str(), "rb");
    if (!fp) {
        // Handle file opening failure
        return;
    }

    char readBuffer[65536];
    rapidjson::FileReadStream is(fp, readBuffer, sizeof(readBuffer));

    rapidjson::Document doc;
    doc.ParseStream(is);

    fclose(fp);

    if (doc.HasParseError()) {
        // Handle parsing error
        return;
    }

    // Extract number of vertices
    if (doc.HasMember("numberOfVerteces") && doc["numberOfVerteces"].IsInt()) {
        node_num = doc["numberOfVerteces"].GetInt();
    }

    nodes = vector<Node>(node_num);

    // Add node details
    for (auto it = doc.MemberBegin(); it != doc.MemberEnd(); ++it) {
        string key = it->name.GetString();
        if (key != "numberOfVerteces") {
            int node_id = stoi(key);
            int node_index = node_id - 1;
            nodes[node_index].id = node_id;
//            vector<int> neighbors;
            const rapidjson::Value &array = it->value;
            for (rapidjson::SizeType i = 0; i < array.Size(); i++) {
                int neighbor_id = array[i].GetInt();
                int neighbor_index = neighbor_id - 1;
                nodes[node_index].neighbors.push_back(&nodes[neighbor_index]);
            }
        }
    }
}

void Graph::reset_heat() {
    for (Node &node: nodes) {
        node.reset_heat();
    }
}

void Graph::display() {
    for (const Node &node: nodes) {
        cout << "Node #" << node.id << endl;
        for (Node *neighbor: node.neighbors) {
            cout << neighbor->id << "\t";
        }
        cout << endl << endl;
    }
}

bool Graph::check_visibility() {
    // let's check if it's visible
    for (Node node: nodes) {
        if (!node.is_visible()) {
            return false;
        }
    }
    return true;
}

bool Graph::check_perfection() {
    // let's check if it's perfect
    for (Node node: nodes) {
        if (node.is_almost_burnt_out()) {
            return false;
        }
    }
    return true;
}
