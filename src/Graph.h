//
// Created by Ethan Eschrich on 12/3/2024.
//

#pragma once

#include "cgraph.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <utility>
#include <set>
#include <vector>
#include <map>

using namespace std;

// Wrapper class for Graph
// Abstracts both traversals and parsing of the inputs
class Graph
{
private:
    Agraph_t* g;
    Agnode_t* from;
    Agnode_t* to;
    vector<Agnode_t*> path;
    set<Agnode_t*> visited;

    bool parse_graph(string path);
    // Wrapper function for getNode, so that we can pass in a string and not a mutable c_str
    Agnode_t* getNode(string s);

public:
    Graph(string path);
    ~Graph();

    // Set the start and end vertices
    // Allows for reusing the same graph object for multiple runs
    void setFromTo(string start, string end);

    // Algorithms for traversing the graph
    // Returns a pair of a vector of the pointers to nodes in the path found, and the set of pointers
    // to nodes visited
    bool dfs();
    bool bfs();
    bool dijkstras();

    void relax(Agedge_t* e, map<Agnode_t*, int> dist, map<Agnode_t*, Agnode_t*> parent);
};