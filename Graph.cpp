// Avishag Minnes
// 213080088
// minnesav@gmail.com

#include "Graph.hpp"
#include <cstddef>

void ariel::Graph::loadGraph(const std::vector<std::vector<int>>& matrix)
{
    int numRows = matrix.size();
    // Check if the matrix is square
    for (const auto& row : matrix) {
        if (row.size() != numRows) {
            std::cerr << "Invalid graph: The graph is not a square matrix.\n" << std::endl;
            return;
        }
    }
    adjMatrix = matrix;
}

std::string ariel::Graph::printGraph()
{
    int vertices = this->adjMatrix.size();
    int edges = 0;

    for (std::size_t i = 0; i < vertices; ++i) {
        for (std::size_t j = i; j < vertices; ++j) { // Start from 'i' to count each edge once
            if (this->adjMatrix[i][j] != 0) {
                edges++;
            }
        }
    }

    std::string result = "Graph with " + std::to_string(vertices) + " vertices and " + std::to_string(edges) + " edges.\n";
    std::cout << result;
    return result;    
}

std::size_t ariel::Graph::size() const
{
    return this->adjMatrix.size();
}

const std::vector<int>& ariel::Graph::operator[](std::size_t index) const
{
    return adjMatrix[index];
}// Const overload for read-only access

int ariel::Graph::edgeCount() const {
    int count = 0;
    for (int i = 0; i < this->size(); i++) {
        for (int j = 0; j < this->size(); j++) {
            if (this->adjMatrix[i][j] != 0) {
                count++;
            }
        }
    }
    return count;
}

ariel::Graph ariel::Graph::operator+(const ariel::Graph& g) const {
    if(this->size()!=g.size()) {
        throw("Graphs are not the same size.\n");
    }
    int size = this->size();
    std::vector<std::vector<int>> mat(size, std::vector<int>(size, 0));
    for(int i =0; i<size; i++) {
        for(int j=0; j<size; j++) {
            mat[i][j] = this->adjMatrix[i][j] + g.adjMatrix[i][j];
        }
    }
    Graph c;
    c.loadGraph(mat);
    return c;
}

ariel::Graph& ariel::Graph::operator+=(const Graph& g) {
    if(this->size()!=g.size()) {
        throw("Graphs are not the same size.\n");
    }
    int size = this->size();
    for(int i =0; i<size; i++) {
        for(int j=0; j<size; j++) {
            this->adjMatrix[i][j] += g.adjMatrix[i][j];
        }
    }
    return *this;
}

ariel::Graph& ariel::Graph::operator+() {
    int size = this->size();
    for(int i =0; i<size; i++) {
        for(int j=0; j<size; j++) {
            this->adjMatrix[i][j] *= 1;
        }
    }
    return *this;
}

ariel::Graph& ariel::Graph::operator++() {
    int size = this->size();
    for(int i =0; i<size; i++) {
        for(int j=0; j<size; j++) {
            this->adjMatrix[i][j]++;
        }
    }
    return *this;
}

ariel::Graph ariel::Graph::operator++(int) {
    int size = this->size();
    for(int i =0; i<size; i++) {
        for(int j=0; j<size; j++) {
            this->adjMatrix[i][j] += 1;
        }
    }
    return *this;
}

ariel::Graph ariel::Graph::operator-(const Graph& g) const {
    if(this->size()!=g.size()) {
        throw("Graphs are not the same size.\n");
    }
    std::vector<std::vector<int>> mat(this->size(), std::vector<int>(this->size(), 0));
    int size = this->size();
    for(int i =0; i<size; i++) {
        for(int j=0; j<size; j++) {
            mat[i][j] = this->adjMatrix[i][j] - g.adjMatrix[i][j];
        }
    }
    Graph c;
    c.loadGraph(mat);
    return c;
}

ariel::Graph& ariel::Graph::operator-=(const Graph& g) {
    if(this->size()!=g.size()) {
        throw("Graphs are not the same size.\n");
    }
    int size = this->size();
    for(int i =0; i<size; i++) {
        for(int j=0; j<size; j++) {
            this->adjMatrix[i][j] -= g.adjMatrix[i][j];
        }
    }
    return *this;
}

ariel::Graph ariel::Graph::operator-() const {
    Graph c;
    c.loadGraph(this->adjMatrix);
    int size = this->size();
    for(int i =0; i<size; i++) {
        for(int j=0; j<size; j++) {
            c.adjMatrix[i][j] = -this->adjMatrix[i][j];
        }
    }
    return c;
}

ariel::Graph ariel::Graph::operator--() {
    int size = this->size();
    for(int i =0; i<size; i++) {
        for(int j=0; j<size; j++) {
            this->adjMatrix[i][j]--;
        }
    }
    return *this;
}

ariel::Graph ariel::Graph::operator--(int) {
    Graph c;
    c.loadGraph(this->adjMatrix);
    int size = this->size();
    for(int i =0; i<size; i++) {
        for(int j=0; j<size; j++) {
            c.adjMatrix[i][j]--;
        }
    }
    return c;
}

ariel::Graph ariel::Graph::operator*(const Graph& g) const {
    if(this->size()!=g.size()) {
        throw("Graphs are not the same size.\n");
    }
    std::vector<std::vector<int>> mat(this->size(), std::vector<int>(this->size(), 0));
    int size = this->size();
    for(int i =0; i<size; i++) {
        for(int j=0; j<size; j++) {
            for(int k=0; k<size; k++){
                mat[i][j] += this->adjMatrix[i][k] * g.adjMatrix[k][j];
            }
        }
    }
    Graph c;
    c.loadGraph(mat);
    return c;
}

ariel::Graph ariel::Graph::operator*(int scalar) const {
    Graph c;
    c.loadGraph(this->adjMatrix);
    int size = this->size();
    for(int i =0; i<size; i++) {
        for(int j=0; j<size; j++) {
            c.adjMatrix[i][j] *= scalar;
        }
    }
    return c;
}

void ariel::Graph::operator*=(int scalar) {
    int size = this->size();
    for(int i =0; i<size; i++) {
        for(int j=0; j<size; j++) {
            this->adjMatrix[i][j] *= scalar;
        }
    }
}

ariel::Graph ariel::Graph::operator/(int scalar) const {
    Graph c;
    c.loadGraph(this->adjMatrix);
    int size = this->size();
    for(int i =0; i<size; i++) {
        for(int j=0; j<size; j++) {
            c.adjMatrix[i][j] /= scalar;
        }
    }
    return c;
}

void ariel::Graph::operator/=(int scalar) {
    int size = this->size();
    for(int i =0; i<size; i++) {
        for(int j=0; j<size; j++) {
            this->adjMatrix[i][j] /= scalar;
        }
    }
}

bool ariel::Graph::operator==(const Graph& g) const {
    if (this->size() != g.size()) {
        return false;
    }
    for (int i = 0; i < this->size(); i++) {
        for (int j = 0; j < this->size(); j++) {
            if (this->adjMatrix[i][j] != g.adjMatrix[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool ariel::Graph::operator!=(const Graph& g) const {
    if (this->size() != g.size()) {
        return true;
    }

    for (int i = 0; i < this->size(); i++) {
        for (int j = 0; j < this->size(); j++) {
            if (this->adjMatrix[i][j] != g.adjMatrix[i][j]) {
                return true;
            }
        }
    }
    return false;
}

bool ariel::Graph::operator>(const Graph& g) const {
    if (this->size() > g.size()) {
        return true;
    } else if (this->size() < g.size()) {
        if (this->edgeCount() > g.edgeCount()) {
            return true;
        }
        return false;
    } else {
        if (*this == g) {
            return true;
        }
        if (this->edgeCount() > g.edgeCount()) {
            return true;
        }
        return false;
    }
}

bool ariel::Graph::operator<(const Graph& g) const {
    if(*this!=g && !(*this>g)) {
        return true;
    }
    return false;
}

bool ariel::Graph::operator>=(const Graph& g) const {
    if(*this==g || *this>g) {
        return true;
    }
    return false;
}

bool ariel::Graph::operator<=(const Graph& g) const {
    if(*this==g || *this<g) {
        return true;
    }
    return false;
}

std::ostream &ariel::operator<<(std::ostream &os, const Graph &g) {
    for(int i = 0; i < g.size(); i++) {
        for(int j = 0; j < g.size(); j++) {
            os << g.adjMatrix[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}
