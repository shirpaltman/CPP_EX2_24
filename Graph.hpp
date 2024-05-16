/*
Author:Shir Altman
ID:325168870
Email: shirpaltman@gmail.com
*/


#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <stddef.h>
#include <stdexcept>
#include <iostream>

using namespace std;


namespace ariel{

    class Graph{
    private:
        std::vector<std:: vector<int>> adjMat;
        int totalVertices;


    public:
        int getNumVertices() const;
        const std::vector<std::vector<int>>& getAdjMat()const;
        bool isEdge(unsigned int ver1, unsigned int ver2)const;
        void loadGraph (const  vector<vector <int>>&matrix);
        void printGraph()const;
        int getWeight(unsigned int numRow,unsigned int numCol)const;
        std::vector<int>getNeighbors(unsigned int ver)const ;
        friend bool operator<(const Graph graph1,const Graph graph2);
        friend bool operator>(const Graph graph1,const Graph graph2);
        friend bool operator==(const Graph& graph1,const Graph& graph2);
        friend bool operator!=(const Graph graph1, const Graph graph2);
        friend bool operator<=(const Graph graph1,const Graph graph2);
        friend bool operator>=( const Graph graph1,const Graph graph2);
        friend Graph operator+ (Graph graph1, Graph graph2);
        friend Graph operator- (Graph graph1, Graph graph2);
        friend Graph operator*(Graph graph1, Graph graph2);
        friend void operator+(Graph& mygraph);
        friend void operator++(Graph& mygraph);
        friend void operator--(Graph& mygraph);
        friend void operator-(Graph& mygraph);
        friend void operator*=(Graph& mygraph,int digit);
        friend void operator<<(ostream os,Graph& myGraph);
        friend void operator/=(Graph& myGraph,int digit);











        Graph(){}
    };
}; // namespace ariel2
#endif
