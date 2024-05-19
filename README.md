
### Author:Shir Altman ###
### ID:325168870 ###
### Email: shirpaltman@gmail.com ###
 



***
### 🎓 Welcome to Shir's Algorithms Adventure! (exe1+2)🚀

### Get ready to embark on an exciting journey through the fascinating algorithms I imlementeted in this assigment here you have a README for what's to come in first taks for this semster 🌟 ###

***
### Algorithms ### 

**Algorithms.cpp contains the implementation of various graph algorithms. It includes functions for performing Depth-First Search (DFS) traversal, checking if a graph is connected, finding the shortest path between two vertices, detecting cycles in a graph, determining if a graph is bipartite, and identifying negative cycles in a graph. These algorithms are essential for analyzing and manipulating graph data structures, offering insights into their properties and behavior.**
*** 




### DFS
This function performs Depth-First Search (DFS) traversal starting from the specified vertex in the given graph (myGraph). It marks visited vertices in the provided vector visited.

 ### isConnected

This function checks whether the given graph (g) is connected or not. It returns true ifthe graph is connected, otherwise false.

### shortestPath
This function finds the shortest path from the starting vertex (start) to the ending vertex (end) in the given graph (g). It returns a string representing the shortest path.

### isCycle
This function checks whether the given graph contains a cycle and returns information about if it found.It utilizes DFS traversal to detect cycles.

### dfsVisit
During DFS search traversal, this function performs the visit operation for each vertex in the graph . It is used as a helper function for cycle detection algorithms.

### buildCycleString
Upon detecting a cycle in the graph, this function constructs a string represntation of the cycle using the information provided by the previous node vector.
### isContainsCycle
This function checks whether the given graph (myGraph) contains any cycles. It returns true if a cycle is found, otherwise false.

### isBipartite
This function determines whether the given graph (myGraph) is bipartite or not. It returns true if the graph is bipartite, otherwise false.

### negativeCycle
This function checks whether the given graph (myGraph) contains a negative cycle. It returns true if a negative cycle is found, otherwise false.


***
### Graph ### 


_**Graph.cpp is the implementation file for the Graph class. This class represents a graph data structure and provides various functionalities for working with graphs, such as loading a graph from an adjacency matrix, printing the graph, checking for edges between vertices, getting the weight of an edge, and retrieving neighbors of a vertex. It encapsulates the underlying adjacency matrix and provides methods to interact with it efficiently.**
***


The *Graph* class is the core component of this library, offering functionalities for representing and manipulating graphs.

**Attributes:**
### adjMat
 A 2D vector representing the adjacency matrix of the graph.
### totalVertices
 The total number of vertices in the graph.

**Methods:**
### getNumVertices
Returns the total number of vertices in the graph.
### getAdjMat
Returns a constant reference to the adjacency matrix of the graph.
### isEdge
Checks if there is an edge between two vertices.
### loadGraph
Loads a graph from a given adjacency matrix.
### printGraph
Prints the graph in a readable format.
### getWeight
Returns the weight of the edge between two vertices.
### getNeighbors
 Returns a vector of neighboring vertices for a given vertex.

***
###  Operator Overloads ###
The Graph class supports a variety of operator overloads for intuitive graph manipulation:
***
 **Friend Functions:**
### operator<
Checks if one graph is less than another graph.
### isSubset
Checks if one graph is a subset of another graph.
### operator>
Checks if one graph is greater than another graph.
### operator==
Checks if two graphs are equal.
### operator!=
Checks if two graphs are not equal.
### operator<=
Checks if one graph is less than or equal to another graph.
### operator>=
Checks if one graph is greater than or equal to another graph.
### operator+
Adds two graphs together.
### operator-
Subtracts one graph from another.
### operator*
Multiplies two graphs together.
### operator+
Unary operator that does not change the graph.
### operator++
Unary operator that adds 1 to every element of the graph.
### operator--
Unary operator that subtracts 1 from every element of the graph.
### operator-
Unary operator that multiplies every element of the graph by -1.
### operator*=
Compound assignment operator that multiplies every element of the graph by a specified digit.
### operator<<
Stream insertion operator that allows printing the graph to an output stream.
### operator/=
Compound assignment operator that divides every element of the graph by a specified digit.