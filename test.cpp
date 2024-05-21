#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test graph addition")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 + g2;
    vector<vector<int>> expectedGraph = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    CHECK(g3.printGraph() == "[0, 2, 1]\n[2, 0, 3]\n[1, 3, 0]");
}

TEST_CASE("Test graph multiplication")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g4 = g1 * g2;
    vector<vector<int>> expectedGraph = {
        {0, 0, 2},
        {1, 0, 1},
        {1, 0, 0}};
    CHECK(g4.printGraph() == "[0, 0, 2]\n[1, 0, 1]\n[1, 0, 0]");
}

TEST_CASE("Invalid operations")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1, 1},
        {1, 0, 2, 1},
        {1, 2, 0, 1}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g5;
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g5.loadGraph(graph2);
    CHECK_THROWS(g5 * g1);
    CHECK_THROWS(g1 * g2);

    // Addition of two graphs with different dimensions
    ariel::Graph g6;
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g6.loadGraph(graph3);
    CHECK_THROWS(g1 + g6);
}

TEST_CASE("OperatorPlusWithEqualSizeGraphs") {
    ariel::Graph g1, g2;
    g1.loadGraph({{1, 2}, {3, 4}});
    g2.loadGraph({{5, 6}, {7, 8}});
    ariel::Graph result = g1 + g2;
    CHECK(result[0][0]== 6);
    CHECK(result[0][1]== 8);
    CHECK(result[1][0]== 10);
    CHECK(result[1][1]== 12);
}

TEST_CASE("OperatorPlusWithDifferentSizeGraphs") {
    ariel::Graph g1, g2;
    g1.loadGraph({{1, 2}, {3, 4}});
    g2.loadGraph({{5, 6, 7}, {8, 9, 10}, {11, 12, 13}});
    CHECK_THROWS(g1 + g2);
}

TEST_CASE("OperatorMinusWithEqualSizeGraphs") {
    ariel::Graph g1, g2;
    g1.loadGraph({{5, 6}, {7, 8}});
    g2.loadGraph({{1, 2}, {3, 4}});
    ariel::Graph result = g1 - g2;
    CHECK(result[0][0]== 4);
    CHECK(result[0][1]== 4);
    CHECK(result[1][0]== 4);
    CHECK(result[1][1]== 4);
}

TEST_CASE("OperatorMinusWithDifferentSizeGraphs") {
    ariel::Graph g1, g2;
    g1.loadGraph({{1, 2}, {3, 4}});
    g2.loadGraph({{5, 6, 7}, {8, 9, 10}, {11, 12, 13}});
    CHECK_THROWS(g1 - g2);
}

TEST_CASE("OperatorMultiplyWithEqualSizeGraphs") {
    ariel::Graph g1, g2;
    g1.loadGraph({{1, 2}, {3, 4}});
    g2.loadGraph({{5, 6}, {7, 8}});
    ariel::Graph result = g1 * g2;
    CHECK(result[0][0]== 19);
    CHECK(result[0][1]== 22);
    CHECK(result[1][0]== 43);
    CHECK(result[1][1]== 50);
}

TEST_CASE("OperatorMultiplyWithDifferentSizeGraphs") {
    ariel::Graph g1, g2;
    g1.loadGraph({{1, 2}, {3, 4}});
    g2.loadGraph({{5, 6, 7}, {8, 9, 10}, {11, 12, 13}});
    CHECK_THROWS(g1 * g2);
}

TEST_CASE("OperatorMultiplyWithScalar") {
    ariel::Graph g1;
    g1.loadGraph({{1, 2}, {3, 4}});
    ariel::Graph result = g1 * 2;
    CHECK(result[0][0]== 2);
    CHECK(result[0][1]== 4);
    CHECK(result[1][0]== 6);
    CHECK(result[1][1]== 8);
}

TEST_CASE("OperatorEqualWithEqualGraphs") {
    ariel::Graph g1, g2;
    g1.loadGraph({{1, 2}, {3, 4}});
    g2.loadGraph({{1, 2}, {3, 4}});
    CHECK(g1 == g2);
}

TEST_CASE("OperatorEqualWithDifferentGraphs") {
    ariel::Graph g1, g2;
    g1.loadGraph({{1, 2}, {3, 4}});
    g2.loadGraph({{5, 6}, {7, 8}});
    CHECK_FALSE(g1 == g2);
}

TEST_CASE("OperatorNotEqualWithEqualGraphs") {
    ariel::Graph g1, g2;
    g1.loadGraph({{1, 2}, {3, 4}});
    g2.loadGraph({{1, 2}, {3, 4}});
    CHECK_FALSE(g1 != g2);
}


TEST_CASE("OperatorLessThanWithSmallerGraphs") {
    ariel::Graph g1, g2;
    g1.loadGraph({{1, 2}, {3, 4}});
    g2.loadGraph({{5, 6}, {7, 8}, {9, 10}});
    CHECK(g1 < g2);
}

TEST_CASE("OperatorLessThanWithEqualGraphs") {
    ariel::Graph g1, g2;
    g1.loadGraph({{1, 2}, {3, 4}});
    g2.loadGraph({{1, 2}, {3, 4}});
    CHECK_FALSE(g1 < g2);
}

TEST_CASE("OperatorGreaterThanWithLargerGraphs") {
    ariel::Graph g1, g2;
    g1.loadGraph({{1, 2}, {3, 4}, {5, 6}});
    g2.loadGraph({{7, 8}});
    CHECK(g1 > g2);
}

TEST_CASE("OperatorGreaterThanWithEqualGraphs") {
    ariel::Graph g1, g2;
    g1.loadGraph({{1, 2}, {3, 4}});
    g2.loadGraph({{1, 2}, {3, 4}});
    CHECK_FALSE(g1 > g2);
}

TEST_CASE("OperatorLessThanOrEqualWithSmallerGraphs") {
    ariel::Graph g1, g2;
    g1.loadGraph({{1, 2}, {3, 4}});
    g2.loadGraph({{5, 6}, {7, 8}, {9, 10}});
    CHECK(g1 <= g2);
}
