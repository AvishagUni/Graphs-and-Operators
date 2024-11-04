# Arithmetic Operators for Graphs

This project provides a C++ library for performing arithmetic and comparison operations on graphs represented by adjacency matrices. The library is designed to support intuitive operator overloading for graph manipulation, making it easier to perform operations like addition, subtraction, and comparison between graph objects.

---

## 📋 Features

### 1. Arithmetic Operators
- **Addition (+ and +=)**: Adds the adjacency matrices of two graphs of the same size. Throws an exception if the graph sizes differ.
- **Subtraction (- and -=)**: Subtracts the adjacency matrix of one graph from another, provided both graphs are of the same size.
- **Multiplication (*)**: Supports both graph-to-graph matrix multiplication and scalar multiplication of a graph's adjacency matrix.

### 2. Unary Operators
- **Unary Plus (+)**: Returns the graph itself without modifying the adjacency matrix.
- **Unary Minus (-)**: Returns a new graph with all values in the adjacency matrix negated.

### 3. Increment and Decrement Operators
- **Prefix and Postfix Increment (++)**: Increments each entry in the adjacency matrix by one.
- **Prefix and Postfix Decrement (--)**: Decrements each entry in the adjacency matrix by one.

### 4. Comparison Operators
- **Equality (==) and Inequality (!=)**: Compares two graphs for equality or inequality based on their sizes and adjacency matrices.
- **Relational Operators (> < >= <=)**: Compares graphs based on size, and if sizes are equal, by edge counts.

### 5. Stream Insertion Operator
- **Stream Insertion (<<)**: Outputs the graph’s adjacency matrix to an output stream (e.g., `std::cout`), formatting it for readability.

### 6. Exception Handling
- Operations involving mismatched graph sizes throw a `runtime_error` exception with a descriptive message, ensuring issues are handled gracefully.

---

## 🛠 Implementation Details

- **Graph Addition/Subtraction**: For addition and subtraction, both graphs must be of the same size. Otherwise, a runtime exception is thrown.
- **Graph Multiplication**: Supports both scalar and matrix multiplication, extending the flexibility for different graph operations.
- **Unary and Increment/Decrement Operators**: Designed to adjust adjacency matrix values, with separate overloads for prefix and postfix versions.
- **Comparison Logic**: Compares graphs based on matrix size and, when sizes match, by the count of edges, providing meaningful insights into graph structure.
- **Stream Output**: Facilitates easy display of graph adjacency matrices for debugging and presentation.

---

## 📂 Project Structure

- **Graph.hpp/cpp**: Defines the graph class with operator overloads for arithmetic, comparison, and unary operations.
- **Main.cpp**: Contains example usage and test cases demonstrating the library’s functionalities.

---

## 🚀 Getting Started

### Requirements
- **C++ Compiler**: Ensure support for C++11 or higher.

### Compilation
To compile the project, run:
```bash
g++ -std=c++11 -o graph_operations Main.cpp Graph.cpp

