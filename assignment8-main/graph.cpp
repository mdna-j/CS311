#include "graph.h"
#include <fstream>
#include <sstream>
#include <queue>
#include <limits>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
// Function to read city data
unordered_map<string, City> readCityData(const string& filename) {
    unordered_map<string, City> cities;
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        exit(1);
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string id, code, name;
        int population, elevation;
        ss >> id >> code >> name >> population >> elevation;
        cities[code] = {code, name, population, elevation};
    }
    file.close();
    return cities;
}

// Function to read road data
unordered_map<string, vector<pair<string, int>>> readRoadData(const string& filename) {
    unordered_map<string, vector<pair<string, int>>> graph;
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        exit(1);
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string from, to;
        int distance;
        ss >> from >> to >> distance;
        graph[from].push_back(make_pair(to, distance));
    }
    file.close();
    return graph;
}

// Dijkstra's algorithm to find the shortest path
pair<int, vector<string>> findShortestPath(
    const unordered_map<string, vector<pair<string, int>>>& graph,
    const string& from, const string& to) {
    unordered_map<string, int> distances;
    unordered_map<string, string> previous;

    // Initialize distances to infinity
    for (auto it = graph.begin(); it != graph.end(); ++it)
        distances[it->first] = numeric_limits<int>::max();

    distances[from] = 0;
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
    pq.push(make_pair(0, from));

    while (!pq.empty()) {
        pair<int, string> current = pq.top();
        pq.pop();

        int dist = current.first;
        string node = current.second;

        if (node == to) break;

        for (size_t i = 0; i < graph.at(node).size(); ++i) {
            string neighbor = graph.at(node)[i].first;
            int weight = graph.at(node)[i].second;

            int new_dist = dist + weight;
            if (new_dist < distances[neighbor]) {
                distances[neighbor] = new_dist;
                previous[neighbor] = node;
                pq.push(make_pair(new_dist, neighbor));
            }
        }
    }

    if (distances[to] == numeric_limits<int>::max()) return make_pair(-1, vector<string>());

    vector<string> path;
    for (string at = to; at != ""; at = previous[at]) path.push_back(at);
    reverse(path.begin(), path.end());
    return make_pair(distances[to], path);
}
