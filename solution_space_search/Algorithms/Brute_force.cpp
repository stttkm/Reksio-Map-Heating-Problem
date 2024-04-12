//
// Created by Krzysztof Mitko on 12.04.2024.
//

#include "Brute_force.h"
#include <iostream>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <fstream>
#include <iostream>

using namespace std;

Brute_force::Brute_force(Graph *graph) {
    this->graph = graph;
}

void Brute_force::generateVectors(std::vector<int> &current, int index) {
    if (index == graph->node_num) {
        this->search_space.push_back(current);
        return;
    }
    for (int i = 0; i <= 2; ++i) {
        current[index] = i;
        generateVectors(current, index + 1);
    }
}


void Brute_force::run() {
    std::vector<int> current(graph->node_num, 0);
//    search_space.push_back(std::vector<int>({2,1,1,0,0,2,0,2,0,0,1,0,2,0,1,1})); //for testing purposes - a known acceptable solution taken from this vid https://youtu.be/uo181tSUpL8?si=TvexG6hbyxt7_oSo
    generateVectors(current, 0);

    // let's iterate over all the possible user inputs
    for (const auto &user_input: this->search_space) {
//         Printing the generated vectors
//                for (int val : user_input) {
//                    std::cout << val << " ";
//                }
//                std::cout << std::endl;

        // HEATING 🔥🔥🔥
        // iterate over the user input region by region
        for (int region_index = 0; region_index < user_input.size(); region_index++) {
            // let's heat it
            int click_num = user_input[region_index];
            for (int j = 0; j < click_num; j++)
                graph->nodes[region_index].heat();
        }

        // SOLUTION JUDGMENT ‍⚖️‍⚖️‍⚖️
        // let's filter out all unacceptable solutions
        if (!graph->check_visibility()) {
            graph->reset_heat();
            continue;
        }
        // let's filter out all perfect solutions
        if (graph->check_perfection()) {
            this->perfect_solutions.push_back(vector<int>(user_input));
            graph->reset_heat();
            continue;
        }
        // let's treat acceptable, but not perfect solutions
        this->acceptable_solutions.push_back(vector<int>(user_input));
        graph->reset_heat();
    }
    save_output();
}

void Brute_force::save_output() {
    // Create a JSON document
    rapidjson::Document doc;
    doc.SetObject();
    rapidjson::Document::AllocatorType &allocator = doc.GetAllocator();

    // Create a rapidjson array to store solutions
    rapidjson::Value acceptable_solutions_json(rapidjson::kArrayType);

    // Populate the solutions array with the vector of vectors
    for (const auto &solution: acceptable_solutions) {
        rapidjson::Value solutionArray(rapidjson::kArrayType);
        for (const auto &elem: solution) {
            solutionArray.PushBack(elem, allocator);
        }
        acceptable_solutions_json.PushBack(solutionArray, allocator);
    }

    // Create a rapidjson array to store solutions
    rapidjson::Value perfect_solutions_json(rapidjson::kArrayType);

    // Populate the solutions array with the vector of vectors
    for (const auto &solution: perfect_solutions) {
        rapidjson::Value solutionArray(rapidjson::kArrayType);
        for (const auto &elem: solution) {
            solutionArray.PushBack(elem, allocator);
        }
        perfect_solutions_json.PushBack(solutionArray, allocator);
    }

    // Add the solutions array to the document
    doc.AddMember("acceptable solutions", acceptable_solutions_json, allocator);
    doc.AddMember("perfect solutions", perfect_solutions_json, allocator);


    // Write the JSON document to a file
    std::ofstream outFile("../solutions/output.json");
    if (outFile.is_open()) {
        rapidjson::StringBuffer buffer;
        rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
        doc.Accept(writer);
        outFile << buffer.GetString() << std::endl;
        outFile.close();
        std::cout << "JSON written to output.json" << std::endl;
    } else {
        std::cerr << "Unable to open file for writing." << std::endl;
    }

}