// Avishag Minnes
// 213080088
// minnesav@gmail.com


// Algorithms.hpp
#ifndef ALGORITHMS_H
#define ALGORITHMS_H



#include "Graph.hpp"



namespace ariel
{
    class Algorithms
    {
    private:
        static void DFS(std::size_t v, std::vector<bool>& visited, const ariel::Graph& g);
        static std::string bellmanFord(ariel::Graph& g, std::size_t src, std::size_t dest);
        static std::string BFS(ariel::Graph& g, std::size_t src, std::size_t dest);
        static bool findCycle(ariel::Graph& g, std::size_t v, std::vector<bool>& visited, std::vector<bool>& recStack, std::vector<int>& parent);
    public:
        static bool isWeighted(ariel::Graph& g);
        static ariel::Graph transpose(ariel::Graph& g);
        static bool isDirected(const ariel::Graph& g);
        static bool isConnected(ariel::Graph& g);
        static std::string shortestPath(ariel::Graph& g, std::size_t start, std::size_t end);
        static bool isContainsCycle(ariel::Graph& g);
        static std::string isBipartite(ariel::Graph& g);
        static std::string negativeCycle(ariel::Graph& g);
    };
}

#endif
