#include<iostream>
#include<string>
#include<queue>
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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == nullptr) {
            return root;
        }

        if (root -> val >= low && root -> val <= high) {
            root -> left = trimBST(root -> left, low, high);
            root -> right = trimBST(root -> right, low, high);
            return root;
        } else if (root -> val < low) {
            return trimBST(root -> right, low, high);
        } else {
            return trimBST(root -> left, low, high);
        } 
    }
};

void breadthFirstSearch(TreeNode* root){ // 广度优先BFS
    queue<TreeNode *> nodeQueue;  
    nodeQueue.push(root);
    TreeNode *node;
    while (!nodeQueue.empty()) {
        node = nodeQueue.front();
        nodeQueue.pop();
        cout << node -> val << " ";//遍历根结点
        if (node -> left) {
            nodeQueue.push(node -> left);  //先将左子树入队
        }
        if (node -> right) {
            nodeQueue.push(node -> right);  //再将右子树入队
        }
    }
}

int main () {
    TreeNode node = TreeNode(3, new TreeNode(0,nullptr,new TreeNode(2,new TreeNode(1),nullptr)),new TreeNode(4));
    Solution s;
    s.trimBST(&node, 1, 3);
    breadthFirstSearch(&node);
}