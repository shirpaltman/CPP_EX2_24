/*
Author:Shir Altman
ID:325168870
Email: shirpaltman@gmail.com
*/

#include "Graph.hpp"
#include <vector>
#include <stack>
#include <stdexcept>
#include <iostream>

namespace ariel
{

    // Graph(int totalVertices) : totalVertices(totalVertices), adjMat(static_cast<int>(totalVertices), std :: vector<size_t> (static_cast<int>(totalVertices),0)){}

    int ariel::Graph::getNumVertices() const
    {
        return this->totalVertices;
    }

    const std::vector<std::vector<int>> &Graph::getAdjMat() const
    {
        return this->adjMat;
    }

    bool ariel::Graph::isEdge(unsigned int ver1, unsigned int ver2) const
    {
        try
        {
            return this->adjMat.at(ver1).at(ver2) != 0;
        }
        catch (const std::out_of_range &e)
        {
            throw std ::out_of_range("the vertex in the index you have asked is out of bounds.");
        }
    }

    void ariel::Graph::printGraph() const
    {
        for (std::vector<int>::size_type i = 0; i < adjMat.size(); i++)
        {
            for (std ::vector<int>::size_type j = 0; j < adjMat[i].size(); j++)
            {
                std::cout << adjMat[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void ariel::Graph::loadGraph(const std ::vector<std ::vector<int>> &mat)
    {

        if (mat.empty())
        {
            throw std ::invalid_argument("this matrix you have entered is empty!");
        }
        size_t numRows = mat.size();
        size_t numCols = mat[0].size();

        for (const auto &row : mat)
        {
            if (row.size() != numCols)
            {
                throw std ::invalid_argument("This matrix isn't rectangular");
            }
        }
        if (numRows != numCols)
        {
            throw std ::invalid_argument("This matrix isn't square");
        }

        totalVertices = mat.size();
        adjMat = mat;
    }

    int ariel::Graph ::getWeight(unsigned int numRow, unsigned int numCol) const
    {
        std::cout<<"entering getweight method with row:" << numRow <<"and colum" << numCol <<std::endl;
        // check that the colum and row meets the conditions (within the limits)
        if (numRow >= totalVertices || numCol >= totalVertices)
        {
            throw std::out_of_range("the node is out of range! ");
        }
        std::cout<<"exiting getweight method with row:" << numRow << "and column" <<numCol << std::endl;
        return adjMat[numRow][numCol];
    }

    std::vector<int> ariel::Graph::getNeighbors(unsigned int ver) const
    {
        std::vector<int> neighbors;
        if (ver < adjMat.size())
        {
            for (std::vector<int>::size_type i = 0; i < adjMat[ver].size(); ++i)
            {
                if (adjMat[ver][i] != 0)
                {
                    neighbors.push_back(static_cast<int>(i));
                }
            }
        }
        return neighbors;
    }

    bool operator==(const Graph &graph1, const Graph &graph2)
    {
        if (graph1.getAdjMat().size() != graph2.getAdjMat().size())
        {
            return false;
        }
        if (graph1.getAdjMat() == graph2.getAdjMat())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator!=(const Graph graph1, const Graph graph2)
    {
        return (!(graph1 == graph2));
    }
    bool operator<(const Graph graph1, const Graph graph2){
        if (isSubset(graph1, graph2))
        {
            return true;
        }
        if (isSubset(graph2, graph1))
        { // check not equal
            return false;
        }
        int graph1CountEdges = 0;
        int graph2CountEdges = 0;
        for (size_t i = 0; i < graph1.getNumVertices(); ++i)
        {
            for (size_t j = 0; j < graph1.getNumVertices(); ++j)
            {
                if (graph1.adjMat[i][j] != 0)
                {
                    ++graph1CountEdges;
                }
                if (graph2.adjMat[i][j] != 0)
                {
                    ++graph2CountEdges;
                }
            }
        }
        if (graph1CountEdges < graph2CountEdges)
        {
            return true;
        }
        if (graph1CountEdges > graph2CountEdges)
        {
           return false;
        }
       return graph1.adjMat.size() < graph2.adjMat.size();
     }
    bool isSubset(const Graph &graph1, const Graph &graph2){
        if (graph1.getNumVertices() >= graph2.getNumVertices())
        {
            return false;
        }
        for (size_t i = 0; i < graph1.getNumVertices(); ++i)
        {
            for (size_t j = 0; j < graph1.getNumVertices(); ++j)
            {
                if (graph1.getAdjMat()[i][j] != 0 && (i >= graph2.getNumVertices() || j >= graph2.getNumVertices() || graph2.getAdjMat()[i][j] == 0))
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool operator>(const Graph graph1, const Graph graph2)
    {
        if (isSubset(graph2, graph1))
        {
            return true;
        }
        if (isSubset(graph1, graph2))
        { // check not equal
            return false;
        }
        int graph1CountEdges = 0;
        int graph2CountEdges = 0;
        for (size_t i = 0; i < graph1.getNumVertices(); ++i)
        {
            for (size_t j = 0; j < graph1.getNumVertices(); ++j)
            {
                if (graph1.adjMat[i][j] != 0)
                {
                    ++graph1CountEdges;
                }
                if (graph2.adjMat[i][j] != 0)
                {
                    ++graph2CountEdges;
                }
            }
        }
        if (graph1CountEdges > graph2CountEdges)
        {
            return true;
        }
        if (graph1CountEdges < graph2CountEdges)
        {
            return false;
        }
        return graph1.adjMat.size() < graph2.adjMat.size();
    }
    bool operator<=(const Graph graph1, const Graph graph2)
    {
        return (!(graph1 > graph2));
    }
    bool operator>=(const Graph graph1, const Graph graph2)
    {
        return (!(graph1 < graph2));
    }
    Graph operator+(Graph graph1,Graph graph2)
    {
        if (graph1.getNumVertices() != graph2.totalVertices)
        {
            throw std::invalid_argument("have to have the same number of vertices ");
        }
        const auto& graph1Mat = graph1.getAdjMat();
        const auto& graph2Mat = graph2.getAdjMat();
        Graph result;

        result.adjMat.resize(static_cast<std::size_t>(graph1.getNumVertices()), 
                     std::vector<int>(static_cast<std::size_t>(graph1.getNumVertices()), 0));

        for (size_t i = 0; i < graph1Mat.size(); ++i)
        {
            for (size_t j = 0; j < graph2Mat.size(); j++)
            {
                result.adjMat[i][j] = graph1.getAdjMat()[i][j] + graph2.getAdjMat()[i][j];
            }
        }
        return result;
    }
    Graph operator-(Graph graph1, Graph graph2)
    {
        if (graph1.getNumVertices() != graph2.totalVertices)
        {
            throw std::invalid_argument("have to have the same number of vertices");
        }
        Graph res;
        res.totalVertices = graph1.totalVertices;
        for (size_t i = 0; i < res.totalVertices; ++i)
        {
            for (size_t j = 0; j < res.totalVertices; j++)
            {
                res.adjMat[i][j] = graph1.getAdjMat()[i][j] - graph2.getAdjMat()[i][j];
            }
        }
        return res;
    }
    Graph operator*(Graph graph1, Graph graph2)
    {
        if (graph1.getNumVertices() != graph2.getNumVertices()){
            throw std::invalid_argument("doesn't follow the rules for multiplucation");
        }
        Graph result;
        result.adjMat.resize(static_cast<std::size_t>(graph1.getNumVertices()), 
                     std::vector<int>(static_cast<std::size_t>(graph1.getNumVertices()), 0));
        for (size_t i = 0; i < result.adjMat.size(); ++i)
        {
            for (size_t j = 0; j < result.adjMat.size(); j++)
            {
                if (i==j){
                    continue;
                }
                for (size_t k = 0; k < result.adjMat.size(); k++)
                {
                result.adjMat[i][j] += graph1.adjMat[i][k] * graph2.adjMat[k][j];
                }
            }
        }
        return result;
    }
    void operator+(Graph &myGraph)
    {
        for (size_t i = 0; i < myGraph.totalVertices; ++i)
        {
            for (size_t j = 0; j < myGraph.totalVertices; j++)
            {
                myGraph.adjMat[i][j] = (myGraph.adjMat[i][j]) * 1;
            }
        }
    }
    void operator++(Graph &myGraph)
    {
        for (size_t i = 0; i < myGraph.adjMat.size(); ++i)
        {
            for (size_t j = 0; j < myGraph.adjMat.size(); ++j)
            {
                ++(myGraph.adjMat[i][j]);
            }
        }
    }
    void operator--(Graph &myGraph)
    {
        for (size_t i = 0; i < myGraph.adjMat.size(); ++i)
        {
            for (size_t j = 0; j < myGraph.adjMat.size(); ++j)
            {
                --(myGraph.adjMat[i][j]);
            }
        }
    }
    void operator-(Graph &myGraph)
    {
        for (size_t i = 0; i < myGraph.adjMat.size(); ++i)
        {
            for (size_t j = 0; j < myGraph.adjMat.size(); ++j)
            {
                myGraph.adjMat[i][j] = myGraph.adjMat[i][j] * (-1);
            }
        }
    }
    void operator*=(Graph &myGraph, int digit)
    {
        for (size_t i = 0; i < myGraph.adjMat.size(); ++i)
        {
            for (size_t j = 0; j < myGraph.adjMat.size(); ++j)
            {
                myGraph.adjMat[i][j] = (myGraph.adjMat[i][j]) * digit;
            }
        }
    }
    void operator<<(std::ostream& os,Graph& myGraph)
    {
        for (const auto &row : myGraph.getAdjMat())
        {
            for (const auto &vertex : row)
            {
                os << vertex << " ";
            }
            os << std::endl;
        }
    }
    void operator/=(Graph &myGraph, int digit)
    {
        if(digit==0){
            throw std::runtime_error("Division by zero");
        }
        for (size_t i = 0; i < myGraph.adjMat.size(); ++i)
        {
            for (size_t j = 0; j < myGraph.adjMat.size(); ++j)
            {
                myGraph.adjMat[i][j] = (myGraph.adjMat[i][j]) / digit;
            }
        }
    }
};
