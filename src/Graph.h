//
// Created by Ethan Eschrich on 12/3/2024.
//

#pragma once

#include "cgraph.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <map>

using namespace std;

class Graph
{
private:
    Agraph_t* g;

public:
    bool parse_graph(string path);
    Graph();
    ~Graph();
};


