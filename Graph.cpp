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
        // check that the colum and row meets the conditions (within the limits)
        if (numRow >= totalVertices || numCol >= totalVertices)
        {
            throw std::out_of_range("the node is out of range! ");
        }
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


    /*Check if two graphs are equal based on their adjacency matrices.
    Compares the sizes of the adjacency matrices first for a quick elimination.*/ 
    bool operator==(const Graph &graph1, const Graph &graph2)
    {
        // Ensure the graphs have the same number of vertices
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
    // Check if two graphs are not equal.
    bool operator!=(const Graph graph1, const Graph graph2)
    {
        return (!(graph1 == graph2));
    }

    bool operator<(const Graph graph1, const Graph graph2){
        if (isSubset(graph1, graph2))
        {
            return true;
        }
        if (isSubset(graph2, graph1)){        // check not equal
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

    // If the number of edges is equal, compare by the number of vertices       
       return graph1.adjMat.size() < graph2.adjMat.size();
     }
     /*Check if one graph is a subset of another.
    Ensures all edges in graph1 exist in the corresponding positions of graph2.*/
    bool isSubset(const Graph &graph1, const Graph &graph2){
        // Graph1 cannot be a subset if it has more or equal vertices than graph2
        if (graph1.getNumVertices() >= graph2.getNumVertices())
        {
            return false;
        }
        // Verify each edge in graph1 exists in graph2
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
    /*Check if one graph is strictly greater than another based on the number of edges and vertices.
    Uses subset relationship and edge counts for comparison.*/
    bool operator>(const Graph graph1, const Graph graph2)
    {
        // Check if graph2 is a proper subset of graph1
        if (isSubset(graph2, graph1))
        {
            return true;
        }
        // If graph1 is a subset of graph2, graph1 cannot be greater
        if (isSubset(graph1, graph2))
        { 
            return false;
        }
         // Count the number of edges in both graphs
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
        // Compare the edge counts
        if (graph1CountEdges > graph2CountEdges)
        {
            return true;
        }
        if (graph1CountEdges < graph2CountEdges)
        {
            return false;
        }
        // If edge counts are equal, compare the number of vertices
        return graph1.adjMat.size() < graph2.adjMat.size();
    }
    bool operator<=(const Graph graph1, const Graph graph2)
    {
        return (!(graph1 > graph2));
    }

    /* Check if one graph is less than or equal to another.
    Utilizes the greater-than operator for comparison.*/   
    bool operator>=(const Graph graph1, const Graph graph2)
    {
        return (!(graph1 < graph2));
    }
   
    /*Add two graphs by summing their adjacency matrices element-wise.
    Ensures both graphs have the same number of vertices.*/
    Graph operator+(Graph graph1,Graph graph2){
        if (graph1.getNumVertices() != graph2.totalVertices)
        {
            throw std::invalid_argument("have to have the same number of vertices ");
        }
        const auto& graph1Mat = graph1.getAdjMat();
        const auto& graph2Mat = graph2.getAdjMat();
        Graph result;

        // Initialize the result adjacency matrix with zeros
        result.adjMat.resize(static_cast<std::size_t>(graph1.getNumVertices()), 
                     std::vector<int>(static_cast<std::size_t>(graph1.getNumVertices()), 0));

       
        // Sum the adjacency matrices element-wise
        for (size_t i = 0; i < graph1Mat.size(); ++i)
        {
            for (size_t j = 0; j < graph2Mat.size(); j++)
            {
                result.adjMat[i][j] = graph1.getAdjMat()[i][j] + graph2.getAdjMat()[i][j];
            }
        }
        return result;
    }
    /*Subtract the adjacency matrix of graph2 from graph1 element-wise.
    Ensures both graphs have the same number of vertices.*/
    Graph operator-(Graph graph1, Graph graph2)
    {
        // Check if both graphs have the same number of vertices
        if (graph1.getNumVertices() != graph2.totalVertices)
        {
            throw std::invalid_argument("have to have the same number of vertices");
        }
            const auto& graph1Mat = graph1.getAdjMat();
            const auto& graph2Mat = graph2.getAdjMat();
            Graph result;

            result.adjMat.resize(static_cast<std::size_t>(graph1.getNumVertices()), 
            std::vector<int>(static_cast<std::size_t>(graph1.getNumVertices()), 0));
            for (size_t i = 0; i < graph1Mat.size(); ++i){
                for (size_t j = 0; j < graph2Mat.size(); j++)
                {
                    result.adjMat[i][j] = graph1.getAdjMat()[i][j] - graph2.getAdjMat()[i][j];
                }
            }
            return result;
    }

    /*Multiply two graphs using matrix multiplication on their adjacency matrices.
    Ensures both graphs have the same number of vertices.*/
    Graph operator*(Graph graph1, Graph graph2)
    {
        if (graph1.getNumVertices() != graph2.getNumVertices()){
            throw std::invalid_argument("doesn't follow the rules for multiplucation");
        }
        Graph result;
        // Initialize the result adjacency matrix with zeros
        result.adjMat.resize(static_cast<std::size_t>(graph1.getNumVertices()), 
                     std::vector<int>(static_cast<std::size_t>(graph1.getNumVertices()), 0));
        
        // Perform matrix multiplication
        for (size_t i = 0; i < result.adjMat.size(); ++i)
        {
            for (size_t j = 0; j < result.adjMat.size(); j++)
            {
                if (i==j){
                    continue;       // Skip diagonal elements if not needed
                }
                for (size_t k = 0; k < result.adjMat.size(); k++)
                {
                result.adjMat[i][j] += graph1.adjMat[i][k] * graph2.adjMat[k][j];
                }
            }
        }
        return result;
    }

    /* Unary plus operator for a graph.
    Multiplies every element of the adjacency matrix by 1 (identity operation).*/
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
    
     /*Pre-increment operator for a graph.
    Increments each element of the adjacency matrix by 1.*/
    void operator++(Graph &myGraph)
    {
        // Increment each element of the adjacency matrix by 1
        for (size_t i = 0; i < myGraph.adjMat.size(); ++i)
        {
            for (size_t j = 0; j < myGraph.adjMat.size(); ++j)
            {
                ++(myGraph.adjMat[i][j]);
            }
        }
    }
    /*Pre-decrement operator for a graph.
    Decrements each element of the adjacency matrix by 1.*/
    void operator--(Graph &myGraph)
    {
         // Decrement each element of the adjacency matrix by 1   
        for (size_t i = 0; i < myGraph.adjMat.size(); ++i)
        {
            for (size_t j = 0; j < myGraph.adjMat.size(); ++j)
            {
                --(myGraph.adjMat[i][j]);
            }
        }
    }
    
    /*Unary minus operator that multiplies each element of the graph's adjacency matrix by -1.
    This operation effectively negates all weights in the graph.*/
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

    /*Multiplies each element of the graph's adjacency matrix by a given digit.
    This scales all weights in the graph by the specified factor.*/
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

    /*Overloads the output stream operator to print the graph's adjacency matrix.
    Outputs each element of the adjacency matrix followed by a space, with rows separated by newlines.*/
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
    /*Divides each element of the graph's adjacency matrix by a given digit.
    This scales down all weights in the graph by the specified factor.
    Throws a runtime error if an attempt is made to divide by zero.*/
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
