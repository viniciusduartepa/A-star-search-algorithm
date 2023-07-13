/**
 @file graph.h
 @brief A class for representing a weighted graph using an adjacency list.
 */
#ifndef DEF_GRAPH
#define DEF_GRAPH

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 @brief A class for representing a weighted graph using an adjacency list.
 */
class Graph {
private:
    unordered_map<string, vector<pair<string, int>>> adjList;/**< An unordered map that stores the adjacency list of the graph. */
public:
    /**
     * @brief Adds a vertex to the graph.
     * @param vertex The vertex to add.
     */
    void addVertex(const string& vertex) {
        adjList[vertex] = vector<pair<string, int>>();
    }

    /**
     * @brief Adds an edge to the graph.
     * @param source The source vertex of the edge.
     * @param dest The destination vertex of the edge.
     * @param distance The weight of the edge.
     */
    void addEdge(const string& source, const string& dest, int distance) {
        adjList[source].push_back(make_pair(dest, distance));
    }
    /**
     * @brief Gets the destinations reachable from a given vertex.
     * @param vertex The vertex to get destinations for.
     * @return A vector of pairs where the first element of each pair is a destination vertex and the second element is the weight of the edge from the source vertex to the destination vertex.
     */
    vector<pair<string,int>> getDestinations(const string& vertex) {
        vector<pair<string,int>> destinations;
        if (this->adjList.find(vertex) != this->adjList.end()) { 
            for (const auto& neighbor : this->adjList.at(vertex)) {
                destinations.push_back(make_pair(neighbor.first, neighbor.second));
            }
        }
        return destinations;
    }
    /**
     * @brief Gets the distance between two vertices in the graph.
     * @param source The source vertex.
     * @param dest The destination vertex.
     * @return The weight of the edge from the source vertex to the destination vertex, or -1 if no such edge exists.
     */
    int getDistance(const string& source, const string& dest) {
        if (adjList.find(source) == adjList.end()) {
            return -1;
        }
        for (const auto& neighbor : adjList[source]) {
            if (neighbor.first == dest) {
                return neighbor.second;
            }
        }
        return -1;
    }

    /**
     * @brief Prints the graph to standard output.
     */
    void printGraph() const {
        for (const auto& [vertex, neighbors] : adjList) {
            cout << vertex << ": ";
            for (const auto& neighbor : neighbors) {
                cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
            }
            cout << endl;
        }
    }
};
#endif //DEF_GRAPH