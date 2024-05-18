/*
Author:Shir Altman
ID:325168870
Email: shirpaltman@gmail.com
*/


#include "doctest.hpp"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;
using namespace ariel;
using namespace Algorithms;
using namespace doctest;

TEST_CASE("Test isConnected")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(Algorithms::isConnected(g) == true);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(Algorithms::isConnected(g) == false);
}

TEST_CASE("Test isContainsCycle a harder test (the graph contains a cycle)")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {0, 0, 0, 1, 0}};
    g.loadGraph(graph);
    CHECK(Algorithms::isContainsCycle(g) == true);
}


TEST_CASE("Test shortestPath")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(Algorithms::shortestPath(g, 0, 4) == "-1");
}
TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(Algorithms::isContainsCycle(g) == false);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(Algorithms::isContainsCycle(g) == true);
}
TEST_CASE("Test isBipartite")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);//"The graph is bipartite: A={0, 2}, B={1}"
    CHECK(Algorithms::isBipartite(g) == true);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(Algorithms::isBipartite(g) == false);

    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 0},
        {1, 0, 3, 0, 0},
        {0, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3); // 
    CHECK(Algorithms::isBipartite(g) == true);
}
TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));
}

TEST_CASE("Test isConnected (disconnected graph) "){
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 0},
        {0, 0, 0}};
    g.loadGraph(graph);
    CHECK(Algorithms::isConnected(g) == false);
}
TEST_CASE("Test isConnected with complex exsample for connected graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {0, 0, 0, 1, 0}};
    g.loadGraph(graph);
    CHECK(Algorithms::isConnected(g) == true);
}

TEST_CASE("Test for shortestPath  (no path)"){
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 0},
        {0, 0, 0}};
    g.loadGraph(graph);
    CHECK(Algorithms::shortestPath(g, 0, 2) == "-1");
}

TEST_CASE("Test isContainsCycle with graph containing cycle"){
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g.loadGraph(graph);
    CHECK(Algorithms::isContainsCycle(g) == true);
}


TEST_CASE("Test shortestPath with complex graph"){
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {0, 0, 0, 1, 0}};
    g.loadGraph(graph);
    CHECK(Algorithms::shortestPath(g, 0, 4) == "0->1->3->4");
}

TEST_CASE("Test isContainsCycle with graph containing no cycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 0},
        {0, 0, 0}};
    g.loadGraph(graph);
    CHECK(Algorithms::isContainsCycle(g) == false);
}
TEST_CASE("Test isConnected with disconnected graph ")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 1, 0}};

    g.loadGraph(graph);

    CHECK(Algorithms::isConnected(g) == false);
}

TEST_CASE("Test isBipartite") {
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 0}};
    g.loadGraph(graph);
    CHECK(Algorithms::isBipartite(g) == false);
}
TEST_CASE("Test isBipartite with disconnected bipartite components") {
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph);
    CHECK(Algorithms::isBipartite(g) == true); 
}
TEST_CASE("Test negativeCycle - Different Cases") {
    // Case 1: No negative cycle
    ariel::Graph graph1;
    graph1.loadGraph({{1, 1, 0}, {1, 0, 1}, {1, 1, 0}});
    CHECK(Algorithms::negativeCycle(graph1) == false); 

    // Case 2: Negative cycle (directed graph)
    ariel::Graph graph2;
    graph2.loadGraph({{0, -1, 2}, {2, 0, -2}, {-1, 1, 0}});
    CHECK(Algorithms::negativeCycle(graph2) == true);

    // Case 3: Negative cycle  (undirected graph)
    ariel::Graph graph3;
    graph3.loadGraph({{0, 1, 1}, {1, 0, -2}, {1, -2, 0}});
    CHECK(Algorithms::negativeCycle(graph3) == true); 
}
TEST_CASE("Test isBipartite - Different Cases") {
    // Case 1: Bipartite graph
    ariel::Graph graph1;
    graph1.loadGraph({{0, 1, 0}, {1, 0, 1}, {0, 1, 0}});
    CHECK(Algorithms::isBipartite(graph1) == true); 

    // Case 2: Bipartite graph
    ariel::Graph graph2;
    graph2.loadGraph({{0, 1, 0}, {1, 0, 1}, {0, 1, 1}});
    CHECK(Algorithms::isBipartite(graph2) == true); 
}

TEST_CASE("Test isBipartite - Non-Bipartite Graph") {
    ariel::Graph g;
    // Constructing a non-bipartite graph where there is an odd-length cycle
    // which violates the property of bipartite graphs
    vector<vector<int>> graph = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 1, 1, 0}
    };
    g.loadGraph(graph);
    CHECK(Algorithms::isBipartite(g) == false); // Graph is not bipartite
}

TEST_CASE("Test operator==") {
    Graph g1, g2, g3;
    g1.loadGraph({{0, 1}, {1, 0}});
    g2.loadGraph({{0, 1}, {1, 0}});
    g3.loadGraph({{0, 1}, {0, 1}});
    
    CHECK(g1==g2);
    CHECK_FALSE(g1 == g3);
}
TEST_CASE("Test operator!=") {
    Graph g1, g2, g3;
    g1.loadGraph({{0, 1}, {1, 0}});
    g2.loadGraph({{0, 1}, {1, 0}});
    g3.loadGraph({{0, 1}, {0, 1}});
    
    CHECK_FALSE(g1!=g2);
    CHECK(g1 != g3);
}




