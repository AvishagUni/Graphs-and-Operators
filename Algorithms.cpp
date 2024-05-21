// Avishag Minnes
// 213080088
// minnesav@gmail.com

#include "Algorithms.hpp"
#include <limits>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>


bool ariel::Algorithms::isDirected(const ariel::Graph& g)
{
    for (std::size_t i = 0; i < g.size(); i++) {
        for (std::size_t j = 0; j < i; j++) {
            if (g[i][j] != g[j][i]) {
                return true;
            }
        }
    }
    return false;
}

ariel::Graph ariel::Algorithms::transpose(ariel::Graph &g)
{
    std::size_t n = g.size();
    std::vector<std::vector<int>> result(n, std::vector<int>(n));
    for (std::size_t i = 0; i < n; i++) {
        for (std::size_t j = 0; j < n; j++) {
            result[j][i] = g[i][j];
        }
    }
    g.loadGraph(result);
    return g;
}

void ariel::Algorithms::DFS(std::size_t v, std::vector<bool>& visited, const ariel::Graph& g)
{
    visited[v] = true;
    for (std::size_t i = 0; i < g.size(); i++) {
        if (g[v][i] != 0 && !visited[i]) {
            DFS(i, visited, g);
        }
    }
}

bool ariel::Algorithms::isConnected(ariel::Graph& g)
{
    std::vector<bool> visited(g.size(), false);
    std::size_t start = 0;  // Assuming there is at least one vertex, adjust as necessary

    DFS(start, visited, g);  // Perform DFS from the start vertex
    for (bool v : visited) {
        if (!v) {
            return false;
        }
    }

    if (isDirected(g)) {  // Check if the graph is directed
        ariel::Graph transposed = transpose(g);
        std::fill(visited.begin(), visited.end(), false);
        DFS(start, visited, transposed);  // DFS on the transposed graph
        for (bool v : visited) {
            if (!v) {
                return false;
            }
        }
    }
    return true;
}

bool ariel::Algorithms::isWeighted(ariel::Graph& g)
{
    std::size_t numVertices = g.size();
    for (std::size_t i = 0; i < numVertices; ++i) {
        for (std::size_t j = 0; j < numVertices; ++j) {
            int weight = g[i][j];
            if (weight != 0 && weight != 1) {
                return true;  // Graph is weighted
            }
        }
    }
    return false;
}

std::string ariel::Algorithms::bellmanFord(ariel::Graph& g, std::size_t src, std::size_t dest)
{
    std::size_t numVertices = g.size();
    std::vector<int> distances(numVertices, std::numeric_limits<int>::max());
    std::vector<int> predecessor(numVertices, -1);  // Predecessor array to reconstruct the path
    distances[src] = 0;

    for (std::size_t i = 0; i < numVertices - 1; i++) {
        for (std::size_t u = 0; u < numVertices; u++) {
            for (std::size_t v = 0; v < numVertices; v++) {
                if (g[u][v] != std::numeric_limits<int>::max() && g[u][v] != 0 &&
                    distances[u] != std::numeric_limits<int>::max() &&
                    distances[u] + g[u][v] < distances[v]) {
                    distances[v] = distances[u] + g[u][v];
                    predecessor[v] = u;
                }
            }
        }
    }

    for (std::size_t u = 0; u < numVertices; u++) {
        for (std::size_t v = 0; v < numVertices; v++) {
            if (g[u][v] != std::numeric_limits<int>::max() && g[u][v] != 0 &&
                distances[u] != std::numeric_limits<int>::max() &&
                distances[u] + g[u][v] < distances[v]) {
                return "-1";
            }
        }
    }

    if (distances[dest] == std::numeric_limits<int>::max()) {
        return "-1";
    } else {
        std::stack<int> path;
        size_t at = dest;
        while(at != -1)
        {
            path.push(at);
            at = (size_t)predecessor[at];
        }

        std::string result;  // Create an empty string to accumulate the output

        // Loop to process the stack until it's empty
        while (!path.empty()) {
            result += std::to_string(path.top());  // Add the top element of the stack to the result string
            path.pop();  // Remove the top element from the stack

            if (!path.empty()) {
                result += "->";  // Add an arrow if there are more elements to process
            }
        }

        return result;  // Return the final constructed string
    }
    }


std::string ariel::Algorithms::BFS(ariel::Graph& g, std::size_t src, std::size_t dest)
{
    std::size_t numVertices = g.size();
    std::vector<bool> visited(numVertices, false);
    std::vector<int> predecessor(numVertices, -1);
    std::queue<std::size_t> queue;

    visited[src] = true;
    queue.push(src);

    while (!queue.empty()) {
        std::size_t current = queue.front();
        queue.pop();

        for (std::size_t i = 0; i < numVertices; ++i) {
            if (g[current][i] && !visited[i]) {
                visited[i] = true;
                predecessor[i] = current;
                queue.push(i);

                if (i == dest) {
                    std::stack<int> path;
                    size_t crawl = dest;
                    path.push(crawl);
                    while ((size_t)predecessor[crawl] != -1) {
                        path.push(predecessor[crawl]);
                        crawl = (size_t)predecessor[crawl];
                    }

                    std::string result;  // Initialize an empty string to store the result

                    // Loop through the stack until it is empty
                    while (!path.empty()) {
                        result += std::to_string(path.top());  // Convert the top element to string and add to the result
                        path.pop();  // Remove the top element from the stack
                        if (!path.empty()) {
                            result += "->";  // Add arrow if there are more elements
                        }
                    }

                    return result;
                }
                }
            }
        }
    return "-1";
}

std::string ariel::Algorithms::shortestPath(ariel::Graph& g, std::size_t start, std::size_t end) {
    if (isWeighted(g)) {
        return bellmanFord(g, start, end);
    } else {
        return BFS(g, start, end);
    }
}

bool ariel::Algorithms::findCycle(ariel::Graph& g, std::size_t v, std::vector<bool>& visited, std::vector<bool>& recStack, std::vector<int> &parent)
{
    visited[v] = true;
    recStack[v] = true;
    std::size_t numVertices = g.size();

    for (std::size_t i = 0; i < numVertices; i++) {
        if (g[v][i] != 0) {  // There is an edge from v to i
            if (!visited[i]) {
                parent[i] = v;
                if (findCycle(g, i, visited, recStack, parent)) {
                    return true;
                }
            } else if (recStack[i] && parent[v] != i) {
                // Cycle found, print the cycle
                std::size_t current = v;
                while (current != i) {
                    std::cout << current << "->";
                    current = (size_t)parent[current];
                }
                std::cout << i << "->" << v << std::endl;
                return true;
            }
        }
    }

    recStack[v] = false;
    return false;
}

bool ariel::Algorithms::isContainsCycle(ariel::Graph& g)
{
    std::size_t numVertices = g.size();
    std::vector<bool> visited(numVertices, false);
    std::vector<bool> recStack(numVertices, false);  // Recursive stack to track back edges
    std::vector<int> parent(numVertices, -1);        // To store the path of nodes

    for (std::size_t v = 0; v < numVertices; v++) {
        if (!visited[v]) {
            if (findCycle(g, v, visited, recStack, parent)) {
                return true;  // Stop after finding the first cycle
            }
        }
    }
    return false;
}

std::string ariel::Algorithms::isBipartite(ariel::Graph& g)
{
    std::size_t numVertices = g.size();
    std::vector<int> color(numVertices, -1);// -1 indicates uncolored, 0 is one color, 1 is another
    std::vector<std::size_t> group1, group2;
    std::queue<std::size_t> q;

    for (std::size_t s = 0; s < numVertices; s++) {
        if (color[s] == -1) {  // Not colored, so color it and check
            color[s] = 0;  // Start coloring with 0
            group1.push_back(s);  // Add to group1
            q.push(s);

            while (!q.empty()) {
                std::size_t u = q.front();
                q.pop();

                for(std::size_t v=0; v<numVertices; v++)
                {
                    if(g[u][v]!= 0) 
                    {
                        if(color[v] == -1)
                        {
                            color[v] = 1-color[u];
                            q.push(v);
                            if(color[v] == 0)
                            {
                                group1.push_back(v);
                            }
                            else
                            {
                                group2.push_back(v);
                            }
                        }
                        else if(color[v]==color[u])
                        {
                            return "0";
                        }

                    }
                }
        }
    }
 }

    std::string result = "The graph is bipartite: A={";

    for (std::size_t i = 0; i < group1.size(); i++) {
        if (i > 0) result += ", ";
        result += std::to_string(group1[i]);
    }

    result += "}, B={";

    for (std::size_t i = 0; i < group2.size(); i++) {
        if (i > 0) result += ", ";
        result += std::to_string(group2[i]);
    }
    result += "}.";
    return result;
}

std::string ariel::Algorithms::negativeCycle(ariel::Graph& g) {
    std::size_t numVertices = g.size();
    std::vector<int> dist(numVertices, std::numeric_limits<int>::max());
    std::vector<int> pred(numVertices, -1);

    // Start from any vertex as the source
    dist[0] = 0;

    // Relax all edges V-1 times
    for (std::size_t step = 0; step < numVertices - 1; ++step) {
        for (std::size_t u = 0; u < numVertices; ++u) {
            for (std::size_t v = 0; v < numVertices; ++v) {
                if (g[u][v] != std::numeric_limits<int>::max() && dist[u] + g[u][v] < dist[v]) {
                    dist[v] = dist[u] + g[u][v];
                    pred[v] = u;
                }
            }
        }
    }

    // Check for a negative weight cycle
    for (std::size_t u = 0; u < numVertices; ++u) {
        for (std::size_t v = 0; v < numVertices; ++v) {
            if (g[u][v] != std::numeric_limits<int>::max() && dist[u] + g[u][v] < dist[v]) {
//                std::cout << "Negative weight cycle found: ";
                std::size_t x = v;
                std::vector<std::size_t> cycle;
                for (std::size_t i = 0; i < numVertices; i++) x = (size_t)pred[x]; // Get to the cycle start
                for (std::size_t current = x; ; current = (size_t)pred[current]) {
                    cycle.push_back(current);
                    if (current == x && cycle.size() > 1) break;
                }
                std::reverse(cycle.begin(), cycle.end());
                std::string result;
                for (std::size_t node : cycle) result += std::to_string(node) + " ";
                result += '\n';
                return result;
            }
        }
    }
    return "No negative weight cycle found.";
}


