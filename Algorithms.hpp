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
        /**
         * Performs a Depth-First Search (DFS) traversal starting from a given vertex.
         *
         * @param v The starting vertex for the DFS traversal.
         * @param visited A vector of boolean values indicating whether each vertex has been visited.
         * @param g The graph on which the DFS traversal is performed.
         */
        static void DFS(std::size_t v, std::vector<bool>& visited, const ariel::Graph& g);
        /**
         * Calculates the shortest path from a source vertex to a destination vertex using the Bellman-Ford algorithm.
         *
         * @param g The graph to perform the algorithm on.
         * @param src The index of the source vertex.
         * @param dest The index of the destination vertex.
         * @return The shortest path from the source vertex to the destination vertex as a string.
         */
        static std::string bellmanFord(ariel::Graph& g, std::size_t src, std::size_t dest);
        /**
         * Performs a breadth-first search (BFS) on the given graph, starting from the source vertex and searching for the destination vertex.
         * 
         * @param g The graph to perform the BFS on.
         * @param src The source vertex.
         * @param dest The destination vertex.
         * @return A string representation of the BFS path from the source to the destination vertex.
         */
        static std::string BFS(ariel::Graph& g, std::size_t src, std::size_t dest);
        /**
         * @brief Finds a cycle in a graph starting from a given vertex.
         * 
         * This function uses depth-first search (DFS) algorithm to find a cycle in a graph.
         * It starts from the specified vertex and explores the graph by recursively visiting its adjacent vertices.
         * The function keeps track of visited vertices and the recursion stack to detect cycles.
         * 
         * @param g The graph to search for cycles in.
         * @param v The starting vertex for the search.
         * @param visited A vector to keep track of visited vertices.
         * @param recStack A vector to keep track of vertices in the recursion stack.
         * @param parent A vector to keep track of the parent of each vertex in the DFS traversal.
         * @return True if a cycle is found, false otherwise.
         */
        static bool findCycle(ariel::Graph& g, std::size_t v, std::vector<bool>& visited, std::vector<bool>& recStack, std::vector<int>& parent);
    public:
        /**
         * Checks if the given graph is weighted.
         *
         * @param g The graph to check.
         * @return True if the graph is weighted, false otherwise.
         */
        static bool isWeighted(ariel::Graph& g);
        /**
         * Transposes the given graph.
         *
         * This function takes a reference to a graph and returns a new graph that is the transpose of the original graph.
         * The transpose of a graph is obtained by reversing the direction of all edges in the graph.
         *
         * @param g The graph to be transposed.
         * @return The transposed graph.
         */
        static ariel::Graph transpose(ariel::Graph& g);
        /**
         * Checks if a given graph is directed.
         *
         * @param g The graph to check.
         * @return True if the graph is directed, false otherwise.
         */
        static bool isDirected(const ariel::Graph& g);
        /**
         * Checks if a graph is connected.
         *
         * This function takes a reference to a `Graph` object and checks if the graph is connected.
         * A graph is considered connected if there is a path between every pair of vertices in the graph.
         *
         * @param g The graph to check for connectivity.
         * @return `true` if the graph is connected, `false` otherwise.
         */
        static bool isConnected(ariel::Graph& g);
        /**
         * Calculates the shortest path between two vertices in a graph.
         *
         * @param g The graph to search for the shortest path.
         * @param start The starting vertex of the path.
         * @param end The ending vertex of the path.
         * @return The shortest path between the start and end vertices as a string.
         */
        static std::string shortestPath(ariel::Graph& g, std::size_t start, std::size_t end);
        /**
         * Checks if a given graph contains a cycle.
         *
         * @param g The graph to check for cycles.
         * @return True if the graph contains a cycle, false otherwise.
         */
        static bool isContainsCycle(ariel::Graph& g);
        /**
         * Determines whether a given graph is bipartite.
         *
         * @param g The graph to check for bipartiteness.
         * @return A string indicating whether the graph is bipartite or not.
         */
        static std::string isBipartite(ariel::Graph& g);
        /**
         * Finds a negative cycle in the given graph.
         *
         * @param g The graph to search for a negative cycle.
         * @return A string representation of the negative cycle found, or an empty string if no negative cycle exists.
         */
        static std::string negativeCycle(ariel::Graph& g);
    };
}

#endif
