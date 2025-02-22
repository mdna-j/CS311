#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// Struct to store city data
struct City {
    string code;
    string name;
    int population;
    int elevation;
};


class Graph {
public:
    struct PathResult {
        int distance;
        std::string route;
    };

    bool loadCities(const std::string& filename);
    bool loadRoads(const std::string& filename);
    bool cityExists(const std::string& code) const;
    std::string getCityName(const std::string& code) const;
    PathResult findShortestPath(const std::string& start, const std::string& end);

private:
    std::unordered_map<std::string, City> cities;
    std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> roads;
};

#endif // GRAPH_H