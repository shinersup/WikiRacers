//
// Created by Ethan Eschrich on 12/3/2024.
//

#include "Graph.h"
#include <cstring>

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

Graph::Graph()
{
    // Taken frmo cgraph.h documentation
    g = agopen("G", Agdirected, NULL);
}

Graph::~Graph()
{

    agclose(g);
}