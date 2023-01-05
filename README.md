# Implementation of a PerfectBinaryTree (PBT) Data Structure from scratch: 
## PerfectBinaryTree.hpp:
This header file is collection of Interfaces to solve problems with PBT DS.
##### Note: A Binary Tree is Perfect, if all Internal Nodes have 2 Children and all Leaf Nodes are at the same Level. 
## main.cpp: 
TheNumberOfNodes is the number of Nodes that will be encapsulated in this->PerfectBinaryTree Object.

TODO: Only accept input n if n belongs to A = {3, 7, 15, 31, 63, ..., log(n-1)}. 

maxl is maximum level of the BT. 

`maxl = log2(n+1) , assume n = 31 
    = log2(31+1)
    = log2(32)
    = 5
    Thus for n = 31,
    the maximum level of this PerfectBinaryTree is 5`
    
## TreeNode.hpp: 
n TreeNode Objects are used to create this->PBT.

TODO: Make the nodes bidirectional (use doubly Linked list nodes).

## PerfectBinaryTree.cpp:    
The PBT object has members for traversing  purpose inside itself.
### - DFS(Depth First Search) Traversal Algorithms are all implemented in recursive fashion:
1- PreorderTraversal

2- InorderTraversal

3- PostorderTraversal
### - BFS(Breadth First Search) Traversal Algorithms are implemented using queue DS:
1- LevelByLevelTraversal:
Returns a vector of nodes visited from left to right

2- LevelorderTraversal:
Returns a vec separated by its level

so we can get the Level of the tree  by :
`vec.size()`

## Run the program in command line:
`$ g++ main.cpp PerfectBinaryTree.cpp -o main`

`./main` 