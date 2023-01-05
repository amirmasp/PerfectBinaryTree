#ifndef PERFECTBINARYTREE_H
#define PERFECTBINARYTREE_H


#include<iostream>
#include<vector>
#include "TreeNode.hpp"
#include <queue>

class PerfectBinaryTree {
    public:   
    PerfectBinaryTree(int n);
    void Print();
    std::vector<int> PreorderTraversal(TreeNode* root);
    std::vector<int> InorderTraversal(TreeNode* root); 
    std::vector<int> PostorderTraversal(TreeNode* root); 
    std::vector<std::vector<int>> LevelorderTraversal(TreeNode* root); // Returns nodes's val by their levels
    std::vector<int> LevelByLevelTraversal(TreeNode* root);
    TreeNode* GetRoot() {return this->tree[0];}

    private:   
    int nodesNumber;
    std::vector<TreeNode*> tree;
    void dfsPreorder(TreeNode* root, std::vector<int>& answer); 
    void dfsInorder(TreeNode* root, std::vector<int>& answer);
    void dfsPostorder(TreeNode* root, std::vector<int>* answer);
    void bfsLeftToRight(TreeNode* root, std::vector<int>& answer);
    void bfsLevelorder(TreeNode* root, std::vector<std::vector<int>>& answer);
};

#endif