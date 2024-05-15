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


namespace ariel{


        //Graph(int totalVertices) : totalVertices(totalVertices), adjMat(static_cast<int>(totalVertices), std :: vector<size_t> (static_cast<int>(totalVertices),0)){}
        

        int ariel::Graph::getNumVertices ()const{
            return this -> totalVertices;
        }
        
        const std::vector<std::vector<int>>& Graph::getAdjMat()const{
            return this->adjMat;
        }


        bool ariel::Graph::isEdge(unsigned int ver1 , unsigned int ver2)const{
            try{
                return this->adjMat.at(ver1).at(ver2) != 0;
            }
            catch (const std:: out_of_range &e){
                throw std :: out_of_range ("the vertex in the index you have asked is out of bounds.");
            }
       
        
        }

        void ariel::Graph::printGraph()const{
            for(std::vector<int>::size_type i=0;i<adjMat.size();i++){
                for(std ::vector<int>::size_type j=0;j<adjMat[i].size();j++){
                    std::cout <<adjMat[i][j]<< " ";
                }
                std::cout << std::endl;
            }
        }



        void ariel::Graph::loadGraph (const std :: vector<std :: vector<int>>& mat){
            
            if(mat.empty()){
                throw std ::invalid_argument("this matrix you have entered is empty!");
            }
            size_t numRows = mat.size();
            size_t numCols = mat[0].size();

            for(const auto& row : mat){
                if(row.size() != numCols){
                    throw std :: invalid_argument("This matrix isn't rectangular");
                }
            }
            if (numRows != numCols){
                throw std :: invalid_argument("This matrix isn't square");
            }
            
            totalVertices = mat.size();
            adjMat =mat ;  
        }

        int ariel::Graph ::getWeight(unsigned int numRow,unsigned int numCol)const{
            //check that the colum and row meets the conditions (within the limits)
            if(numRow >= totalVertices || numCol >= totalVertices){
                throw std::out_of_range("the node is out of range! ");
            }
            return adjMat[numRow][numCol];

        }


        
        std::vector<int> ariel::Graph:: getNeighbors(unsigned int ver)const {
            std::vector<int> neighbors;
            if (ver< adjMat.size()){
                for(std::vector<int>::size_type i =0; i< adjMat[ver].size();++i){
                    if(adjMat[ver][i]!=0){
                        neighbors.push_back(static_cast<int>(i));
                    }
                }
            }
            return neighbors;
        }

};





