#include "PerfectBinaryTree.hpp"

// Constructor of Tree object
// ***************************************************************************************************
PerfectBinaryTree::PerfectBinaryTree(int n) : nodesNumber(n){
    int count = 1;
        
    // Data Structure 
    for (int i = 0; i < this->nodesNumber; i++) {
        TreeNode* node = new TreeNode();  
        node->val = i;
        this->tree.push_back(node);      
    }
        
    // Algorithm 
    for (int i = 0; i < tree.size() / 2; i++) {
        tree[i]->left = tree[count];
        count++;
        tree[i]->right = tree[count];
        count++;
    }
}
// ***************************************************************************************************  

// ***************************************************************************************************
std::vector<int> PerfectBinaryTree::PreorderTraversal(TreeNode* root) {
    std::vector<int> answer;
    this->dfsPreorder(root, answer);

    return answer;
}
// ***************************************************************************************************

// DFS Algorithms are implemented here using Recursion Consept
// ***************************************************************************************************
void PerfectBinaryTree::dfsPreorder(TreeNode* root, std::vector<int>& answer) {
        if (!root) {// Base case
            return;
        }
        answer.push_back(root->val);               // visit the root
        this->dfsPreorder(root->left, answer);     // traverse left subtree
        this->dfsPreorder(root->right, answer);    // traverse right subtree
    }
// ***************************************************************************************************

// ***************************************************************************************************
std::vector<int> PerfectBinaryTree::InorderTraversal(TreeNode* root) {
    std::vector<int> answer;
    this->dfsInorder(root, answer);

    return answer;
}
// ***************************************************************************************************
 
// ***************************************************************************************************
void PerfectBinaryTree::dfsInorder(TreeNode* root, std::vector<int>& answer) {
        if (!root) { // Base case
            return;
        }

        this->dfsInorder(root->left, answer);     // traverse left subtree
        answer.push_back(root->val);               // visit the root
        this->dfsInorder(root->right, answer);    // traverse right subtree
    }
// ***************************************************************************************************

// ***************************************************************************************************
std::vector<int> PerfectBinaryTree::PostorderTraversal(TreeNode* root) {
    std::vector<int>* answer = new std::vector<int>();
    this->dfsPostorder(root, answer);

    return *answer;
}
// ***************************************************************************************************

// ***************************************************************************************************
void PerfectBinaryTree::dfsPostorder(TreeNode* root, std::vector<int>* answer) {
    if (!root) {// Base case
        return;
    }
        
    this->dfsPostorder(root->left, answer);     // traverse left subtree
    this->dfsPostorder(root->right, answer);    // traverse right subtree
    answer->push_back(root->val);               // visit the root
}   
// ***************************************************************************************************

// ***************************************************************************************************
std::vector<int> PerfectBinaryTree::LevelByLevelTraversal(TreeNode* root) {
    std::vector<int> answer;
    this->bfsLeftToRight(root, answer);

    return answer;
}
// ***************************************************************************************************

// This BFS algorithm is implemented here by using Queues Abstract Data Structure from STL
// ***************************************************************************************************
void PerfectBinaryTree::bfsLeftToRight(TreeNode* root, std::vector<int>& answer) {
    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* frontOfQ = q.front();
        if (frontOfQ) {
            q.push(frontOfQ->left);
            q.push(frontOfQ->right);
            answer.push_back(frontOfQ->val);
            q.pop();
            }
            else {// is nullptr, do not travers
                q.pop();// just pop rge node from q
            }
        } 
    }
// ***************************************************************************************************

// ***************************************************************************************************
std::vector<std::vector<int>> PerfectBinaryTree::LevelorderTraversal(TreeNode* root) {
    std::vector<std::vector<int>> answers;
    this->bfsLevelorder(root, answers);

    return answers;
}
// ***************************************************************************************************

// Given the root of a binary tree, return the level order traversal of its nodes' values.
//  (i.e., from left to right, level by level).
// ***************************************************************************************************
void PerfectBinaryTree::bfsLevelorder(TreeNode* root, std::vector<std::vector<int>>& answers) {
    std::queue<TreeNode*> q;
    TreeNode* currentNode;
    // Push root to the q
    if (root) {
        q.push(root);
    }
    // if q is empty, traversing has been finished
    while (!q.empty()) {
        // We just need all elements of q at his level = q.size
        int level = q.size();
        // Remember: returned answers is a collection of thisLevel vectors:
        // answers = [[level_0_Nodes->val], [level_1_Nodes->val],  ...,[level_n_Nodes->val]]
        // [level_n_Nodes->val] == thisLevel == all nodes in queue in this q.size() 
        std::vector<int> thisLevelNodes;

        // Travers into queue nodes with same level Right Now
        for (int i = 0; i < level; i++) {
            // currentNode is front node in the q with const size
            currentNode = q.front();
                
            if (currentNode) {
                // We have address of the front node so pop it up from q
                q.pop();
                    
                // Here, we are changing the size of q by pushing 
                // left and right children of currentNode into q w/o
                // affecting this->current loop at all. We got the fixed size for this loop
                q.push(currentNode->left);
                q.push(currentNode->right);
                thisLevelNodes.push_back(currentNode->val);                                          
            }
            else {// it is nullptr, do not travers
                q.pop();// just pop up the node from q
            }
        }

        if (thisLevelNodes.size() > 0) {
            answers.push_back(thisLevelNodes);
        }
            
        thisLevelNodes.erase (thisLevelNodes.begin(), thisLevelNodes.end());            
    }            
} 
// ***************************************************************************************************

// ***************************************************************************************************
void PerfectBinaryTree::Print() {
    for (int i = 0; i < tree.size(); i++) { 
        if (this->tree[i]->left || this->tree[i]->right) {
            std::cout << "Node = "<< this->tree[i]->val <<  ", left = " << this->tree[i]->left->val  <<
                ", right = " << this->tree[i]->right->val << std::endl;
        }
        else {
            std::cout << "Node = "<< this->tree[i]->val << ", left = nullptr  , right nullptr" << std::endl;
        }
    }
}
// ***************************************************************************************************