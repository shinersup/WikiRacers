//
// Created by Ethan Eschrich on 12/3/2024.
//

#include "Graph.h"
#include <cstring>
#include <stack>
#include <algorithm>

// https://stackoverflow.com/questions/1120140/how-can-i-read-and-parse-csv-files-in-c
bool Graph::parse_graph(string path)
{
    // Open file from path
    ifstream wiki(path);

    // Stored as Edge-List, so iterate through each edge
    string edge;
    while(getline(wiki, edge))
    {
        // Make edge a string stream
        istringstream sStream(edge);

        // Initialize strings for values
        string fromID;
        string fromName;
        string toID;
        string toName;

        getline(sStream, fromID, ',');
        getline(sStream, fromName, ',');
        getline(sStream, toID, ',');
        getline(sStream, toName);

        // Because the cgraph function only takes non-const c-strings,
        // Create temporary non-const duplicates
        // NOTE: A hack but it works
        char* cFromName = strdup(fromName.c_str());
        char* cToName = strdup(toName.c_str());

        // Adds the two nodes and the edge to the graph
        // NOTE: createflag = 1 means it won't return null if it already exists
        Agnode_t* n = agnode(g, cFromName, 1);
        Agnode_t* m = agnode(g, cToName, 1);
        agedge(g, n, m, "", 1);
    }

    return 1;
};

// Constructor that automatically builds graph from .csv file
Graph::Graph(string path)
{
    // Taken from cgraph.h documentation
    g = agopen("G", Agdirected, NULL);
    parse_graph(path);
}

Graph::~Graph()
{
    agclose(g);
}

// Code taken from lecture notes 8a - Graph Terminology and Implementation
bool Graph::dfs()
{
    bool discovered = false;
    // Initialize the stack
    stack<Agnode_t*> s;

    // Push and visit the "from" node
    s.push(from);
    visited.insert(from);

    // While the stack is not empty,
    while(!s.empty() && !discovered)
    {
        // Pop the top node
        Agnode_t* node = s.top();
        s.pop();

        // Taken from https://www.graphviz.org/pdf/cgraph.pdf documentation
        // For each outgoing edge of the node,
        for (auto e = agfstout(g,node); e; e = agnxtout(g,e))
        {
            // If the "to" vertex is a neighbor,
            if (e->node == to)
            {
                // We have discovered a path, so set the boolean to true and break
                discovered = true;
            }

            // If the node has not already been visited,
            if (visited.find(e->node) == visited.end())
            {
                // Visit the node and push to the stack
                visited.insert(e->node);
                s.push(e->node);
            }
        }
    }

    // If there was an s-t path discovered, unpack it
    if(discovered)
    {
        path.push_back(to);
        while(!s.empty())
        {
            path.push_back(s.top());
            s.pop();
        }
        reverse(path.begin(), path.end());
        return true;
    }

    return false;
}