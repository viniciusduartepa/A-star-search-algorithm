
/**
 * @file main.cpp
 * @brief This file contains the implementation of a solver for finding the shortest path between cities in Romania using
 * Greedy Best-First Search and A* Search.
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "graph.hpp"
#include "initializer.hpp"

using namespace std;


/**
 * @class Solver
 * @brief This class contains the methods to find the shortest path between cities in Romania using Greedy Best-First Search and A* Search.
 */
class Solver{
    private:
    Graph romaniaMap;/*< A Graph object that represents the Romania Map. */
    unordered_map<string,int> heuristics;/* An unordered map containing the heuristic function that estimates the distance from each city to Bucharest. */
    public:
    /**
    * @brief The constructor of the Solver class that initializes the Romania Map and the heuristic function.
    */
    Solver(){
        initializeRomaniaMap(romaniaMap);
        heuristics=straightLineDistanceToBucharest;
        string origin;
        int choice=0;
        while (choice != 3) {
            cout << "Welcome to Romania Map Solver!\n\n";
            cout << "Please select an option:\n";
            cout << "1. Find the shortest path between a city and Bucharest using Greedy Best-First Search.\n";
            cout << "2. Find the shortest path between two cities using A* Search.\n";
            cout << "3. Exit.\n\n";
            cout << "Enter your choice (1-3): ";
            cin >> choice;
            switch (choice) {
                case 1:
                    cout << "\nEnter the origin city: ";
                    cin >> origin;
                    this->getShortestPath(origin, "Bucharest", "greedy");
                    break;
                case 2:
                    cout << "\nEnter the origin city: ";
                    cin >> origin;
                    this->getShortestPath(origin, "Bucharest", "astar");
                    break;
                case 3:
                    cout << "\nExiting program...\n";
                    break;
                default:
                    cout << "\nInvalid choice. Please try again.\n";
                    break;
            }
            cout << "\n";
         }
    }
    
    /**
     * @brief This method finds the shortest path between two cities using either Greedy Best-First Search or A* Search.
     * @param origin The origin city.
     * @param destination The destination city.
     * @param searchMethod The search method to use ("greedy" or "astar").
     * @return void
     */
    void getShortestPath(string origin,string destination,string searchMethod){
        if(origin==destination) return;
        vector<string> Path;
        Path.push_back(origin);
        pair<string,int> nextCity;
        int distance = 0;
        string actualCity = origin;
        while(actualCity != destination){
            if(searchMethod=="greedy")nextCity = greedyBestChildren(actualCity);
            if(searchMethod=="astar")nextCity = aStarBestChildren(actualCity);
            distance += romaniaMap.getDistance(actualCity,nextCity.first);
            actualCity=nextCity.first;
            Path.push_back(actualCity);
        }
        cout << "\nPath:\n";
        for (auto const& city : Path) {
			cout << city << endl;
		}
        cout << "Distance: " << distance << endl;
    }

    /**
     * @brief This method returns the child with the minimum heuristic value using Greedy Best-First Search.
     * @param origin The parent node.
     * @return pair<string,int> The minimum heuristic value.
     */
    pair<string,int> greedyBestChildren(string origin){
        vector<pair<string,int>> destinies = romaniaMap.getDestinations(origin);
        vector<pair<string,int>> validHeuristics;
        for (auto const& destiny : destinies) {
			for (auto const& heuristic : heuristics) {
			if(destiny.first ==heuristic.first){
				validHeuristics.push_back(make_pair(heuristic.first,heuristic.second));
			}
			}	
		}
        pair<string,int> minHeuristic =  *min_element(validHeuristics.begin(), validHeuristics.end(),
                               [](const auto& a, const auto& b) {
                                   return a.second < b.second;
                               });
        return minHeuristic;
    }

    /**
     * @brief This method returns the child with the minimum heuristic value using A* Search.
     * @param origin The parent node.
     * @return pair<string,int> The minimum heuristic value.
     */
    pair<string,int> aStarBestChildren(string origin){
        vector<pair<string,int>> destinies = romaniaMap.getDestinations(origin);
        vector<pair<string,int>> validHeuristics;
        for (auto const& destiny : destinies) {
			for (auto const& heuristic : heuristics) {
			if(destiny.first ==heuristic.first){
				validHeuristics.push_back(make_pair(heuristic.first,destiny.second + heuristic.second));
			}
			}	
		}
        pair<string,int> minAStar =  *min_element(validHeuristics.begin(), validHeuristics.end(),
                               [](const auto& a, const auto& b) {
                                   return a.second < b.second;
                               });
        return minAStar;
    }
};

int main() {
    Solver S;
    return 0;
}