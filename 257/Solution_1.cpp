#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> treePaths;
        if (root == nullptr) { //
            return treePaths;
        }
        
        string pres = to_string(root -> val);

        if (root -> left == nullptr && root -> right == nullptr) {
            treePaths.push_back(pres);
            return treePaths;
        }

        vector<string> leftPaths = binaryTreePaths(root -> left);
        vector<string> rightPaths = binaryTreePaths(root ->right);

        for (int i = 0; i < leftPaths.size(); i++){
            treePaths.push_back(pres + "->" + leftPaths[i]); 
        }
        for (int i = 0; i < rightPaths.size(); i++){
            treePaths.push_back(pres + "->" + rightPaths[i]);
        }
        return treePaths;
    }
};

int main() {
    TreeNode* root = new TreeNode(1,new TreeNode(2,new TreeNode(3),new TreeNode(4)),new TreeNode(5));
    Solution solution;
    vector<string> paths = solution.binaryTreePaths(root);
    for (int i = 0; i < paths.size(); i++) {
        cout << paths[i] << endl;
    }
}