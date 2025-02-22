#include <iostream>
#include <string>
#include "graph.h"


// Main function
int main() {
    // Input city codes
    string from_code, to_code;
    cout << "Enter the code for the starting city: ";
    cin >> from_code;
    cout << "Enter the code for the destination city: ";
    cin >> to_code;

    // Read city and road data
    auto cities = readCityData("city.txt");
    auto graph = readRoadData("road.txt");

    // Validate city codes
    if (cities.find(from_code) == cities.end()) {
        cerr << "Invalid city code: " << from_code << endl;
        return 1;
    }
    if (cities.find(to_code) == cities.end()) {
        cerr << "Invalid city code: " << to_code << endl;
        return 1;
    }

    // Print program header
    cout << "Author: Jose Medina\n";
    cout << "Date: 12/01/2024\n";
    cout << "Course: CS311 (Data Structures and Algorithms)\n";
    cout << "Description: Program to find the shortest route between cities\n";
    cout << "----------------------------------------------------------------\n";

    // Print city details
    cout << "From City: " << cities[from_code].name << ", population " << cities[from_code].population
         << ", elevation " << cities[from_code].elevation << "\n";
    cout << "To City: " << cities[to_code].name << ", population " << cities[to_code].population
         << ", elevation " << cities[to_code].elevation << "\n";

    // Find shortest path
    auto result = findShortestPath(graph, from_code, to_code);
    int distance = result.first;
    vector<string> path = result.second;

    if (distance == -1) {
        cout << "No route from " << cities[from_code].name << " to " << cities[to_code].name << "\n";
    } else {
        cout << "The shortest distance from " << cities[from_code].name << " to " << cities[to_code].name
             << " is " << distance << "\n";
        cout << "Through the route: ";
        for (size_t i = 0; i < path.size(); ++i) {
            cout << cities[path[i]].name;
            if (i < path.size() - 1) cout << "->";
        }
        cout << "\n";
    }

    return 0;
}

