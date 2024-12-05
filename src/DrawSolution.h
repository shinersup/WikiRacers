#pragma once

#include <string>
#include <vector>
#include <unordered_set>

void DrawSolution(
    const std::string& outfile,
    const std::vector<std::pair<std::string, std::string>>& edges,
    const std::unordered_set<std::string>& visited,
    const std::vector<std::pair<std::string, std::string>>& solution
    );
