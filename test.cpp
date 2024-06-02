// Avishag Minnes
// 213080088
// minnesav@gmail.com

#include "doctest.h"
#include "Algorithms.hpp"
#include <sstream>

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
    CHECK(g3.printGraph() == "[0, 2, 1]\n[2, 0, 3]\n[1, 3, 0]\n");

    // Addition of two graphs with different dimensions
    ariel::Graph g5;
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g5.loadGraph(graph2);
    CHECK_THROWS(g5 + g1);
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
    CHECK(g4.printGraph() == "[0, 0, 2]\n[1, 0, 1]\n[1, 0, 0]\n");

    // Multiplication of two graphs with different dimensions
    ariel::Graph g5;
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g5.loadGraph(graph2);
    CHECK_THROWS(g5 * g1);

    // Multiplication of graph with scalar
    ariel::Graph g6 = g1 * 2;
    vector<vector<int>> expectedGraph2 = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    CHECK(g6.printGraph() == "[0, 2, 0]\n[2, 0, 2]\n[0, 2, 0]\n");
}

TEST_CASE("Invalid operations")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g5;
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g5.loadGraph(graph2);
    CHECK_THROWS(g5 * g1);

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

TEST_CASE("Test unary plus operator")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 2, 0},
        {-3, 0, 1},
        {2, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2 = +g1;
    CHECK(g2.printGraph() == "[0, 2, 0]\n[-3, 0, 1]\n[2, 1, 0]\n");
}

TEST_CASE("Test unary minus operator")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, -6, 0},
        {4, 0, -1},
        {10, 0, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2 = -g1;
    CHECK(g2.printGraph() == "[0, 6, 0]\n[-4, 0, 1]\n[-10, 0, 0]\n");
}

TEST_CASE("Test graph equality")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g2.loadGraph(graph2);
    CHECK((g1 == g2) == true);

    ariel::Graph g3;
    vector<vector<int>> graph3 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 1}};
    g3.loadGraph(graph3);
    CHECK((g1 == g3) == false);
}

TEST_CASE("Test graph inequality")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g2.loadGraph(graph2);
    CHECK((g1 != g2) == false);

    ariel::Graph g3;
    vector<vector<int>> graph3 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 1}};
    g3.loadGraph(graph3);
    CHECK((g1 != g3) == true);
}

TEST_CASE("Test graph addition assignment")
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
    g1 += g2;
    vector<vector<int>> expectedGraph = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    CHECK(g1.printGraph() == "[0, 2, 1]\n[2, 0, 3]\n[1, 3, 0]\n");
}

TEST_CASE("Test += operator")
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
    g1 += g2;
    CHECK(g1.printGraph() == "[0, 2, 1]\n[2, 0, 3]\n[1, 3, 0]\n");

    ariel::Graph g3;
    vector<vector<int>> grpah1 = {
        {0, 12, 17, -2},
        {24, 0, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}};

    g3.loadGraph(grpah1);
    ariel::Graph g4;
    vector<vector<int>> grpah2 = {
        {0, 1, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {0, 0, 1, 0}};
    g4.loadGraph(grpah2);
    g3 += g4;
    CHECK(g3.printGraph() == "[0, 13, 17, -2]\n[25, 0, 2, 0]\n[0, 1, 0, 1]\n[0, 0, 1, 0]\n");

    // Addition of two graphs with different dimensions
    ariel::Graph g6;
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g6.loadGraph(graph3);
    CHECK_THROWS(g1 += g6);
}

TEST_CASE("Test - operator")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 6, 0},
        {4, 0, 1},
        {10, 0, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g2.loadGraph(graph2);
    ariel::Graph g3 = g1 - g2;
    vector<vector<int>> expectedGraph = {
        {0, 5, 0},
        {3, 0, 0},
        {10, -1, 0}};
    CHECK(g3.printGraph() == "[0, 5, 0]\n[3, 0, 0]\n[10, -1, 0]\n");

    // Subtraction of two graphs with different dimensions
    ariel::Graph g4;
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g4.loadGraph(graph3);
    CHECK_THROWS(g1 - g4);
}

TEST_CASE("Test -= operator")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 6, 0},
        {4, 0, 1},
        {10, 0, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g2.loadGraph(graph2);
    g1 -= g2;
    vector<vector<int>> expectedGraph = {
        {0, 5, 0},
        {3, 0, 0},
        {10, -1, 0}};
    CHECK(g1.printGraph() == "[0, 5, 0]\n[3, 0, 0]\n[10, -1, 0]\n");

    ariel::Graph g3;
    vector<vector<int>> grpah1 = {
        {0, 12, 17, -2},
        {24, 0, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}};

    g3.loadGraph(grpah1);
    ariel::Graph g4;
    vector<vector<int>> grpah2 = {
        {0, 1, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {0, 0, 1, 0}};
    g4.loadGraph(grpah2);
    g3 -= g4;
    CHECK(g3.printGraph() == "[0, 11, 17, -2]\n[23, 0, 0, 0]\n[0, -1, 0, -1]\n[0, 0, -1, 0]\n");

    // Subtraction of two graphs with different dimensions
    ariel::Graph g6;
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g6.loadGraph(graph3);
    CHECK_THROWS(g1 -= g6);
}

TEST_CASE("Test * operator")
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
    ariel::Graph g3 = g1 * g2;
    vector<vector<int>> expectedGraph = {
        {0, 0, 2},
        {1, 0, 1},
        {1, 0, 0}};
    CHECK(g3.printGraph() == "[0, 0, 2]\n[1, 0, 1]\n[1, 0, 0]\n");

    // Multiplication of two graphs with different dimensions
    ariel::Graph g4;
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g4.loadGraph(graph2);
    CHECK_THROWS(g1 * g4);

    // Multiplication of graph with scalar
    ariel::Graph g5 = g1 * 2;
    vector<vector<int>> expectedGraph2 = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    CHECK(g5.printGraph() == "[0, 2, 0]\n[2, 0, 2]\n[0, 2, 0]\n");
}

TEST_CASE("Test pre-increment operator")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ++g1;
    CHECK(g1.printGraph() == "[0, 2, 1]\n[2, 0, 2]\n[1, 2, 0]\n");

    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};

    g2.loadGraph(weightedGraph);
    ++g2;
    CHECK(g2.printGraph() == "[0, 2, 2]\n[2, 0, 3]\n[2, 3, 0]\n");

    // try to increment a graph with negative values
    ariel::Graph g3;
    vector<vector<int>> grpah1 = {
        {0, 12, 17, -2},
        {24, 0, 1, 0},
        {0, -8, 0, 0},
        {230, -10, 0, 0}};
    g3.loadGraph(grpah1);
    ++g3;
    CHECK(g3.printGraph() == "[0, 13, 18, -1]\n[25, 0, 2, 1]\n[1, -7, 0, 1]\n[231, -9, 1, 0]\n");
}

TEST_CASE("Test pre-decrement operator")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 6, 0},
        {4, 0, 1},
        {10, 0, 0}};
    g1.loadGraph(graph);
    --g1;
    CHECK(g1.printGraph() == "[0, 5, -1]\n[3, 0, 0]\n[9, -1, 0]\n");

    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    --g2;
    CHECK(g2.printGraph() == "[0, 0, 0]\n[0, 0, 1]\n[0, 1, 0]\n");

    // try to decrement a graph with negative values
    ariel::Graph g3;
    vector<vector<int>> grpah1 = {
        {0, 12, 17, -2},
        {24, 0, 1, 0},
        {0, -8, 0, 0},
        {230, -10, 0, 0}};
    g3.loadGraph(grpah1);
    --g3;
    CHECK(g3.printGraph() == "[0, 11, 16, -3]\n[23, 0, 0, -1]\n[-1, -9, 0, -1]\n[229, -11, -1, 0]\n");
}

TEST_CASE("Test post-increment operator")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2 = g1++;
    CHECK(g1.printGraph() == "[0, 2, 1]\n[2, 0, 2]\n[1, 2, 0]\n");
    CHECK(g2.printGraph() == "[0, 1, 0]\n[1, 0, 1]\n[0, 1, 0]\n");

    ariel::Graph g3;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g3.loadGraph(weightedGraph);
    ariel::Graph g4 = g3++;
    CHECK(g3.printGraph() == "[0, 2, 2]\n[2, 0, 3]\n[2, 3, 0]\n");
    CHECK(g4.printGraph() == "[0, 1, 1]\n[1, 0, 2]\n[1, 2, 0]\n");

    // try to increment a graph with negative values
    ariel::Graph g5;
    vector<vector<int>> grpah1 = {
        {0, 12, 17, -2},
        {24, 0, 1, 0},
        {0, -8, 0, 0},
        {230, -10, 0, 0}};
    g5.loadGraph(grpah1);
    ariel::Graph g6 = g5++;
    CHECK(g5.printGraph() == "[0, 13, 18, -1]\n[25, 0, 2, 1]\n[1, -7, 0, 1]\n[231, -9, 1, 0]\n");
    CHECK(g6.printGraph() == "[0, 12, 17, -2]\n[24, 0, 1, 0]\n[0, -8, 0, 0]\n[230, -10, 0, 0]\n");
}

TEST_CASE("Test post-decrement operator")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 6, 0},
        {4, 0, 1},
        {10, 0, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2 = g1--;
    CHECK(g1.printGraph() == "[0, 5, -1]\n[3, 0, 0]\n[9, -1, 0]\n");
    CHECK(g2.printGraph() == "[0, 6, 0]\n[4, 0, 1]\n[10, 0, 0]\n");

    ariel::Graph g3;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g3.loadGraph(weightedGraph);
    ariel::Graph g4 = g3--;
    CHECK(g3.printGraph() == "[0, 0, 0]\n[0, 0, 1]\n[0, 1, 0]\n");
    CHECK(g4.printGraph() == "[0, 1, 1]\n[1, 0, 2]\n[1, 2, 0]\n");

    // try to decrement a graph with negative values
    ariel::Graph g5;
    vector<vector<int>> grpah1 = {
        {0, 12, 17, -2},
        {24, 0, 1, 0},
        {0, -8, 0, 0},
        {230, -10, 0, 0}};
    g5.loadGraph(grpah1);
    ariel::Graph g6 = g5--;
    CHECK(g5.printGraph() == "[0, 11, 16, -3]\n[23, 0, 0, -1]\n[-1, -9, 0, -1]\n[229, -11, -1, 0]\n");
    CHECK(g6.printGraph() == "[0, 12, 17, -2]\n[24, 0, 1, 0]\n[0, -8, 0, 0]\n[230, -10, 0, 0]\n");
}

TEST_CASE("Test / operator") {
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 6, 0},
        {4, 0, 1},
        {10, 0, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2 = g1 / 2;
    vector<vector<int>> expectedGraph = {
        {0, 3, 0},
        {2, 0, 0},
        {5, 0, 0}};
    CHECK(g2.printGraph() == "[0, 3, 0]\n[2, 0, 0]\n[5, 0, 0]\n");

    ariel::Graph g3;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g3.loadGraph(weightedGraph);
    ariel::Graph g4 = g3 / 2;
    vector<vector<int>> expectedGraph2 = {
        {0, 0, 0},
        {0, 0, 1},
        {0, 1, 0}};
    CHECK(g4.printGraph() == "[0, 0, 0]\n[0, 0, 1]\n[0, 1, 0]\n");

    // Division of graph with scalar 0
    CHECK_THROWS(g1 / 0);
}

TEST_CASE("Test /= operator") {
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 6, 0},
        {4, 0, 1},
        {10, 0, 0}};
    g1.loadGraph(graph);
    g1 /= 2;
    vector<vector<int>> expectedGraph = {
        {0, 3, 0},
        {2, 0, 0},
        {5, 0, 0}};
    CHECK(g1.printGraph() == "[0, 3, 0]\n[2, 0, 0]\n[5, 0, 0]\n");

    ariel::Graph g3;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g3.loadGraph(weightedGraph);
    g3 /= 2;
    vector<vector<int>> expectedGraph2 = {
        {0, 0, 0},
        {0, 0, 1},
        {0, 1, 0}};
    CHECK(g3.printGraph() == "[0, 0, 0]\n[0, 0, 1]\n[0, 1, 0]\n");

    // Division of graph with scalar 0
    CHECK_THROWS(g1 /= 0);
}

TEST_CASE("Test *= operator graphs") {
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
    g1 *= g2;
    vector<vector<int>> expectedGraph = {
        {0, 0, 2},
        {1, 0, 1},
        {1, 0, 0}};
    CHECK(g1.printGraph() == "[0, 0, 2]\n[1, 0, 1]\n[1, 0, 0]\n");

    // Multiplication of two graphs with different dimensions
    ariel::Graph g3;
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g3.loadGraph(graph2);
    CHECK_THROWS(g1 *= g3);
}

TEST_CASE("Test < operator") {
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g2.loadGraph(graph2);
    CHECK((g1 < g2) == false);

    ariel::Graph g3;
    vector<vector<int>> graph3 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 1}};
    g3.loadGraph(graph3);
    CHECK((g1 < g3) == true);
}

TEST_CASE("Test > operator") {
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g2.loadGraph(graph2);
    CHECK((g1 > g2) == false);

    ariel::Graph g3;
    vector<vector<int>> graph3 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 1}};
    g3.loadGraph(graph3);
    CHECK((g1 > g3) == false);
}

TEST_CASE("Test <= operator") {
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g2.loadGraph(graph2);
    CHECK((g1 <= g2) == true);

    ariel::Graph g3;
    vector<vector<int>> graph3 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 1}};
    g3.loadGraph(graph3);
    CHECK((g1 <= g3) == true);
}

TEST_CASE("Test >= operator") {
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g2.loadGraph(graph2);
    CHECK((g1 >= g2) == true);

    ariel::Graph g3;
    vector<vector<int>> graph3 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 1}};
    g3.loadGraph(graph3);
    CHECK((g1 >= g3) == false);
}

TEST_CASE("Test << operator") {
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    std::ostringstream os;
    os << g1;
    CHECK(os.str() == "[0, 1, 0]\n[1, 0, 1]\n[0, 1, 0]\n");
}
