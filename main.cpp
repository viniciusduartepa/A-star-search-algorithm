#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Graph {
private:
    unordered_map<string, vector<pair<string, int>>> adjList;
public:
    
    void addVertex(const string& vertex) {
        adjList[vertex] = vector<pair<string, int>>();
    }

    void addEdge(const string& source, const string& dest, int weight) {
        adjList[source].push_back(make_pair(dest, weight));
    }

    vector<pair<string,int>> getDestinations(const string& vertex) {
    vector<pair<string,int>> destinations;
    if (this->adjList.find(vertex) != this->adjList.end()) {
        for (const auto& neighbor : this->adjList.at(vertex)) {
            destinations.push_back(make_pair(neighbor.first, neighbor.second));
        }
    }
    return destinations;
    }

    int getDistance(const string& source, const string& dest) {
    if (adjList.find(source) == adjList.end()) {
        // Source vertex not found in graph
        return -1;
    }

    for (const auto& neighbor : adjList[source]) {
        if (neighbor.first == dest) {
            // Found the destination vertex
            return neighbor.second;
        }
    }

    // Destination vertex not found among neighbors of source vertex
    return -1;
}


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

class Solver{
    private:
    Graph romeniaMap;
    unordered_map<string,int> heuristics;
    public:
    Solver(){
        romeniaMap.addVertex("Arad");
		romeniaMap.addEdge("Arad","Zerind",75);
		romeniaMap.addEdge("Arad","Sibiu",140);
		romeniaMap.addEdge("Arad","Timisoara",118);

		romeniaMap.addVertex("Bucharest");
		romeniaMap.addEdge("Bucharest","Giurgiu",90);
		romeniaMap.addEdge("Bucharest","Urziceni",85);
		romeniaMap.addEdge("Bucharest","Fagaras",211);
		romeniaMap.addEdge("Bucharest","Pitesti",101);
		
		romeniaMap.addVertex("Craiova");
		romeniaMap.addEdge("Craiova","Pitesti",138);
		romeniaMap.addEdge("Craiova","Rimnicu Vilcea",146);
		romeniaMap.addEdge("Craiova","Drobeta",120);

		romeniaMap.addVertex("Drobeta");
		romeniaMap.addEdge("Drobeta","Craiova",120);
		romeniaMap.addEdge("Drobeta","Mehadia",75);

		romeniaMap.addVertex("Eforie");
		romeniaMap.addEdge("Eforie","Hirsova",86);

		romeniaMap.addVertex("Fagaras");
		romeniaMap.addEdge("Fagaras","Sibiu",99);
		romeniaMap.addEdge("Fagaras","Bucharest",211);

		romeniaMap.addVertex("Giurgiu");
		romeniaMap.addEdge("Giurgiu","Bucharest",90);

		romeniaMap.addVertex("Hirsova");
		romeniaMap.addEdge("Hirsova","Eforie",86);
		romeniaMap.addEdge("Hirsova","Urziceni",98);

		romeniaMap.addVertex("Iasi");;
		romeniaMap.addEdge("Mehadia","Lugoj",70);
		romeniaMap.addEdge("Mehadia","Drobeta",75);

		romeniaMap.addVertex("Neamt");
		romeniaMap.addEdge("Neamt","Iasi",87);

		romeniaMap.addVertex("Oradea");
		romeniaMap.addEdge("Oradea","Sibiu",151);
		romeniaMap.addEdge("Oradea","Zerind",71);

		romeniaMap.addVertex("Pitesti");
		romeniaMap.addEdge("Pitesti","Rimnicu Vilcea",97);
		romeniaMap.addEdge("Pitesti","Bucharest",101);
		romeniaMap.addEdge("Pitesti","Craiova",138);

		romeniaMap.addVertex("Rimnicu Vilcea");
		romeniaMap.addEdge("Rimnicu Vilcea","Craiova",146);
		romeniaMap.addEdge("Rimnicu Vilcea","Pitesti",97);
		romeniaMap.addEdge("Rimnicu Vilcea","Sibiu",80);

		romeniaMap.addVertex("Sibiu");
		romeniaMap.addEdge("Sibiu","Oradea",151);
		romeniaMap.addEdge("Sibiu","Arad",140);
		romeniaMap.addEdge("Sibiu","Rimnicu Vilcea",80);
		romeniaMap.addEdge("Sibiu","Fagaras",99);

		romeniaMap.addVertex("Timisoara");
		romeniaMap.addEdge("Timisoara","Arad",118);
		romeniaMap.addEdge("Timisoara","Lugoj",111);

		romeniaMap.addVertex("Urziceni");
		romeniaMap.addEdge("Urziceni","Hirsova",98);
		romeniaMap.addEdge("Urziceni","Vaslui",142);
		romeniaMap.addEdge("Urziceni","Bucharest",85);

		romeniaMap.addVertex("Vaslui");
		romeniaMap.addEdge("Vaslui","Iasi",92);
		romeniaMap.addEdge("Vaslui","Urziceni",142);

		romeniaMap.addVertex("Zerind");
		romeniaMap.addEdge("Zerind","Arad",75);
		romeniaMap.addEdge("Zerind","Oradea",71);

        heuristics.insert({"Arad",366});
		heuristics.insert({"Bucharest",0});
		heuristics.insert({"Craiova",160});
		heuristics.insert({"Drobeta",242});
		heuristics.insert({"Eforie",161});
		heuristics.insert({"Fagaras",176});
		heuristics.insert({"Giurgiu",77});
		heuristics.insert({"Hirsova",151});
		heuristics.insert({"Iasi",226});
		heuristics.insert({"Lugoj",244});
		heuristics.insert({"Mehadia",241});
		heuristics.insert({"Neamt",234});
		heuristics.insert({"Oradea",380});
		heuristics.insert({"Pitesti",100});
		heuristics.insert({"Rimnicu Vilcea",193});
		heuristics.insert({"Sibiu",253});
		heuristics.insert({"Timisoara",329});
		heuristics.insert({"Urziceni",80});
		heuristics.insert({"Vaslui",199});
		heuristics.insert({"Zering",374});
    }
    void greedySearch(string origin,string destination){
        if(origin==destination) return;
        vector<string> visited;
        pair<string,int> nextCity;
        int distance = 0;
        string actualCity = origin;
        visited.push_back(actualCity);
        while(actualCity != destination){

            nextCity = minHeuristic(actualCity);
            distance += romeniaMap.getDistance(actualCity,nextCity.first);
            actualCity=nextCity.first;
            visited.push_back(actualCity);
        }
        cout << "Path:\n";
        for (auto const& city : visited) {
			cout << city << endl;
		}
        cout << "Distance: " << distance << endl;
    }
    pair<string,int> minHeuristic(string origin){
        vector<pair<string,int>> destinies = romeniaMap.getDestinations(origin);
        vector<pair<string,int>> validAStars;
        for (auto const& destiny : destinies) {
			for (auto const& heuristic : heuristics) {
			if(destiny.first ==heuristic.first){
				validAStars.push_back(make_pair(heuristic.first,heuristic.second));
			}
			}	
		}
        pair<string,int> minHeuristic =  *min_element(validAStars.begin(), validAStars.end(),
                               [](const auto& a, const auto& b) {
                                   return a.second < b.second;
                               });
        return minHeuristic;
    }

    void aStarSearch(string origin,string destination){
        if(origin==destination) return;
        vector<string> visited;
        pair<string,int> nextCity;
        int distance = 0;
        string actualCity = origin;
        visited.push_back(actualCity);
        while(actualCity != destination){

            nextCity = minAStar(actualCity);
            distance += romeniaMap.getDistance(actualCity,nextCity.first);
            actualCity=nextCity.first;
            visited.push_back(actualCity);
        }
        cout << "Path:\n";
        for (auto const& city : visited) {
			cout << city << endl;
		}
        cout << "Distance: " << distance << endl;
    }

    pair<string,int> minAStar(string origin){
        vector<pair<string,int>> destinies = romeniaMap.getDestinations(origin);
        vector<pair<string,int>> validAStars;
        for (auto const& destiny : destinies) {
			for (auto const& heuristic : heuristics) {
			if(destiny.first ==heuristic.first){
				validAStars.push_back(make_pair(heuristic.first,destiny.second + heuristic.second));
			}
			}	
		}
        pair<string,int> minAStar =  *min_element(validAStars.begin(), validAStars.end(),
                               [](const auto& a, const auto& b) {
                                   return a.second < b.second;
                               });
        return minAStar;
    }



  
};

int main() {
    Solver S;
    S.greedySearch("Arad","Bucharest");
    S.aStarSearch("Arad","Bucharest");
    return 0;
}
