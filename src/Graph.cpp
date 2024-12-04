//
// Created by Ethan Eschrich on 12/3/2024.
//

#include "Graph.h"

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

        // TODO: Add this data to the graph pointer g
    }

    return 1;
};

Graph::~Graph()
{
    //agclose(g);
}