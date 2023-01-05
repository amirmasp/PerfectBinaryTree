#ifndef TREENODE_H
#define TREENODE_H

class TreeNode {
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr), parent(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr), parent(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right), parent(nullptr) {}
    TreeNode* Parent() { return this->getParent(); }

    private:
    TreeNode* parent;
    TreeNode* getParent() { return this->parent; }
    
};

#endif