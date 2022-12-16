#include <iostream>
#include <vector>
#include "PerfectBinaryTree.hpp"
using namespace std;

// ***************************************************************************************************
int main () {
    int TheNumberOfNodes = 31;
    //  TheNumberOfNodes belongs to A = {3, 7, 15, 31, 63, }
    PerfectBinaryTree Tree(TheNumberOfNodes);
    
    vector<vector<int>> ans;
    ans = Tree.LevelorderTraversal(Tree.GetRoot());
    cout << "MaxLevel of Tree = " << ans.size() << "\n[";
    // Also we could compute MaxLevel = log2(TheNumberOfNodes+1) beforhand
    for (auto level: ans) {
        cout << "[";
        for (int nodeVal: level) {
            if (nodeVal != level.back()) {
                cout << nodeVal << ", ";
            }
            else {
                cout << nodeVal;
            }           
        }
        cout << "],";
    }
    cout << "]\n";

    return 0;
}
// ***************************************************************************************************