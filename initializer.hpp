/**
 * @file initializer.hpp
 * @brief Header file containing function and data structure declarations for initializing a graph representing a map of Romania, and the straight distance et.
*/

#ifndef DEF_INITIALIZER
#define DEF_INITIALIZER

#include <unordered_map>
#include "graph.hpp"

using namespace std;

/**
 * @brief Function to initialize a graph representing a map of Romania.
 * @param romaniaMap A reference to a Graph object to be initialized.
*/
void initializeRomaniaMap(Graph& romaniaMap){
    romaniaMap.addVertex("Arad");
    romaniaMap.addEdge("Arad","Zerind",75);
    romaniaMap.addEdge("Arad","Sibiu",140);
    romaniaMap.addEdge("Arad","Timisoara",118);

    romaniaMap.addVertex("Bucharest");
    romaniaMap.addEdge("Bucharest","Giurgiu",90);
    romaniaMap.addEdge("Bucharest","Urziceni",85);
    romaniaMap.addEdge("Bucharest","Fagaras",211);
    romaniaMap.addEdge("Bucharest","Pitesti",101);
    
    romaniaMap.addVertex("Craiova");
    romaniaMap.addEdge("Craiova","Pitesti",138);
    romaniaMap.addEdge("Craiova","Rimnicu Vilcea",146);
    romaniaMap.addEdge("Craiova","Drobeta",120);

    romaniaMap.addVertex("Drobeta");
    romaniaMap.addEdge("Drobeta","Craiova",120);
    romaniaMap.addEdge("Drobeta","Mehadia",75);

    romaniaMap.addVertex("Eforie");
    romaniaMap.addEdge("Eforie","Hirsova",86);

    romaniaMap.addVertex("Fagaras");
    romaniaMap.addEdge("Fagaras","Sibiu",99);
    romaniaMap.addEdge("Fagaras","Bucharest",211);

    romaniaMap.addVertex("Giurgiu");
    romaniaMap.addEdge("Giurgiu","Bucharest",90);

    romaniaMap.addVertex("Hirsova");
    romaniaMap.addEdge("Hirsova","Eforie",86);
    romaniaMap.addEdge("Hirsova","Urziceni",98);

    romaniaMap.addVertex("Iasi");;
    romaniaMap.addEdge("Mehadia","Lugoj",70);
    romaniaMap.addEdge("Mehadia","Drobeta",75);

    romaniaMap.addVertex("Neamt");
    romaniaMap.addEdge("Neamt","Iasi",87);

    romaniaMap.addVertex("Oradea");
    romaniaMap.addEdge("Oradea","Sibiu",151);
    romaniaMap.addEdge("Oradea","Zerind",71);

    romaniaMap.addVertex("Pitesti");
    romaniaMap.addEdge("Pitesti","Rimnicu Vilcea",97);
    romaniaMap.addEdge("Pitesti","Bucharest",101);
    romaniaMap.addEdge("Pitesti","Craiova",138);

    romaniaMap.addVertex("Rimnicu Vilcea");
    romaniaMap.addEdge("Rimnicu Vilcea","Craiova",146);
    romaniaMap.addEdge("Rimnicu Vilcea","Pitesti",97);
    romaniaMap.addEdge("Rimnicu Vilcea","Sibiu",80);

    romaniaMap.addVertex("Sibiu");
    romaniaMap.addEdge("Sibiu","Oradea",151);
    romaniaMap.addEdge("Sibiu","Arad",140);
    romaniaMap.addEdge("Sibiu","Rimnicu Vilcea",80);
    romaniaMap.addEdge("Sibiu","Fagaras",99);

    romaniaMap.addVertex("Timisoara");
    romaniaMap.addEdge("Timisoara","Arad",118);
    romaniaMap.addEdge("Timisoara","Lugoj",111);

    romaniaMap.addVertex("Urziceni");
    romaniaMap.addEdge("Urziceni","Hirsova",98);
    romaniaMap.addEdge("Urziceni","Vaslui",142);
    romaniaMap.addEdge("Urziceni","Bucharest",85);

    romaniaMap.addVertex("Vaslui");
    romaniaMap.addEdge("Vaslui","Iasi",92);
    romaniaMap.addEdge("Vaslui","Urziceni",142);

    romaniaMap.addVertex("Zerind");
    romaniaMap.addEdge("Zerind","Arad",75);
    romaniaMap.addEdge("Zerind","Oradea",71);
}

/**
 * @brief An unordered map that stores the straight line distances between cities and Bucharest.
 * The keys are strings representing city names, and the values are integers representing distances in kilometers.
*/

unordered_map<string,int> straightLineDistanceToBucharest = {
    {"Arad",366},
	{"Bucharest",0},
	{"Craiova",160},
	{"Drobeta",242},
	{"Eforie",161},
	{"Fagaras",176},
	{"Giurgiu",77},
	{"Hirsova",151},
	{"Iasi",226},
	{"Lugoj",244},
	{"Mehadia",241},
	{"Neamt",234},
	{"Oradea",380},
	{"Pitesti",100},
	{"Rimnicu Vilcea",193},
	{"Sibiu",253},
	{"Timisoara",329},
	{"Urziceni",80},
	{"Vaslui",199},
	{"Zering",374},
    };


#endif //DEF_INITIALIZER