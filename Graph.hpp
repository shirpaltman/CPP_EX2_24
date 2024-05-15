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


namespace ariel{

    class Graph{
    private:
        std::vector<std:: vector<int>> adjMat;
        int totalVertices;


    public:
        int getNumVertices() const;
        const std::vector<std::vector<int>>& getAdjMat()const;
        bool isEdge(unsigned int ver1, unsigned int ver2)const;
        void loadGraph (const std :: vector<std ::vector <int>>&matrix);
        void printGraph()const;
        int getWeight(unsigned int numRow,unsigned int numCol)const;
        std::vector<int>getNeighbors(unsigned int ver)const ;
        Graph(){}
    };
}; // namespace ariel2
#endif
