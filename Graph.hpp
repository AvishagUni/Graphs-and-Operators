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
//    private:
//        std::vector<std::vector<int>> adjMatrix;
    public:
        std::vector<std::vector<int>> adjMatrix;
        void loadGraph(const std::vector<std::vector<int>>& matrix);
        std::string printGraph();
        [[nodiscard]] std::size_t size() const;
        const std::vector<int>& operator[](std::size_t index) const;  // Const overload for read-only access
        int edgeCount() const;
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
        void operator*=(int scalar);
        Graph operator/(int scalar) const;
        void operator/=(int scalar);
        bool operator==(const Graph& g) const;
        bool operator!=(const Graph& g) const;
        bool operator>(const Graph& g) const;
        bool operator<(const Graph& g) const;
        bool operator>=(const Graph& g) const;
        bool operator<=(const Graph& g) const;
        friend std::ostream &operator<<(std::ostream &os, const Graph &g);
    };
}

#endif
