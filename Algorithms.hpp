/*
Author:Shir Altman
ID:325168870
Email: shirpaltman@gmail.com
*/


#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include "Graph.hpp"
using namespace ariel;
namespace Algorithms{

        static void DFS(const Graph& myGraph,size_t vertex,std ::vector<bool>& visited);
        bool isConnected(const Graph& g);
        std::string shortestPath(const Graph& g , int start , int end );
        bool isContainsCycle(const Graph& myGraph);
        bool isBipartite(const Graph& myGraph);
        bool negativeCycle(const Graph &myGraph);
        static bool containsCircleHelper(const Graph &myGraph, size_t ver, std::vector<int>& color, std::vector<size_t> &parent);
        static std::string isCycle( const Graph& myGraph);
        static unsigned int dfsVisit( const Graph& myGraph,size_t u, std::vector<unsigned int>& color,std::vector<unsigned int >& prev);
        static std::string buildCycleString(unsigned int firstInCycle,const std::vector<unsigned int> & prev);

}; // namespace ariel
#endif