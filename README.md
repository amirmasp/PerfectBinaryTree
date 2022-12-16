# Implementing a PerfectBinaryTree Data Structures from scratch: 
    ## PerfectBinaryTree.hpp:
        This is going to be a an Interface to solve problems with PerfectBinaryTree DS.
        NOTE: < A Binary Tree is Perfect, if all Internal Nodes have 2 
            Children and all Leaf Nodes are at the same Level. >
    ## main.cpp: 
        TheNumberOfNodes is the number of Nodes that will be encapsulated in 
        this->PerfectBinaryTree Object.
        TODO: Only accept input n if n belongs to A = {3, 7, 15, 31, 63, ..., }. 
        TheNumberOfNodes could be only any of Integers {3, 7, 15, 31, 63, ...} 
        l is maximum level of the BT. 
        l = log2(n+1) , assume n = 31 
          = log2(31+1)
          = log2(32)
          = 5
        Thus for n = 31,
        the maximum level of this PerfectBinaryTree is 5
    
    ## TreeNode.hpp: 
        We implement TreeNode Object to create n of them inside the PBT.

    ## PerfectBinaryTree.cpp:    
        This DataType object has some member functions to Travers
        1- DFS(Depth First Search) Traversal Algorithms are all implemented in recursive fashion:
            - PreorderTraversal
            - InorderTraversal
            - PostorderTraversal
        2- BFS(Breadth First Search) Traversal Algorithms are implemented using queue DS.:
            - LevelByLevelTraversal:
                returns a vector of nodes visited from left to right
            - LevelorderTraversal:
                returns a vec separated by its level
                So we can get the Level of the tree  by :
                    vec.size()
