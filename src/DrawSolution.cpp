//
// Created by Ethan on 12/4/2024.
//
#include "Graph.h"
#include <iostream>
#include <fstream>
#include<string>
#include <unordered_set>
#include <vector>

void DrawSolution(string outfile, vector<pair<string, string>> edges, unordered_set<string> visited, vector<pair<string, string>>
                                                                                                         solution){
    //Create file to write DOT file to
    ofstream file(outfile);
    file << "Digraph MyGraph {\n";
    //Drawing edges of graph
    for (auto edge : edges){
        file << " \"" << edge.first << "\" -> \"" << edge.second << "\";\n";
    }
    //Selects all edges that were visited and changes them to a different color
    for (auto node : visited){
        file << "  \"" << node << "\" [color=red, style=filled, fillcolor=lightblue];\n";
    }
    // If-Else statement to check if a solution is present
    if (solution.size() == 0){
        cout << "No solution is present." << endl;
    }
    else {
        //Draws correct path taken for the solution and draws it in green
        for (auto &edge: solution) {
            file << "  \"" << edge.first << "\" -> \"" << edge.second
                 << "\" [color=green, penwidth=2.0];\n";
        }
    }
    file << "}\n";
    file.close();

}
int main()
{
    Graph g;
    g.parse_graph("C:\\Users\\ethan\\DSA\\WikiRacers\\Test.csv");
}