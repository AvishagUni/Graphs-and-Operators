// Avishag Minnes
// 213080088
// minnesav@gmail.com

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>

namespace ariel
{
    class Graph
    {
   private:
       std::vector<std::vector<int>> adjMatrix;
    public:
        // memeber functions
        void loadGraph(const std::vector<std::vector<int>>& matrix);
        std::string printGraph() const;
        std::size_t size() const;
        int edgeCount() const;

        // operators
        const std::vector<int>& operator[](std::size_t index) const;  // Const overload for read-only access
        Graph operator+(const Graph& g) const;
        Graph& operator+=(const Graph& g);
        Graph& operator+();
        Graph& operator++();
        Graph operator++(int);
        Graph operator-(const Graph& g) const;
        Graph& operator-=(const Graph& g);
        Graph operator-() const;
        Graph operator--();
        Graph operator--(int);
        Graph operator*(const Graph& g) const;
        Graph operator*(int scalar) const;
        Graph& operator*=(const Graph& g);
        void operator*=(int scalar);
        Graph operator/(int scalar) const;
        void operator/=(int scalar);
        bool operator==(const Graph& g) const;
        bool operator!=(const Graph& g) const;
        bool operator>(const Graph& g) const;
        bool operator<(const Graph& g) const;
        bool operator>=(const Graph& g) const;
        bool operator<=(const Graph& g) const;

        // friend functions
        friend std::ostream &operator<<(std::ostream &os, const Graph &g);
    };
} // namespace ariel

#endif // GRAPH_H
