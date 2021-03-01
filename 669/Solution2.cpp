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
            return nullptr;
        }

        // 先将根变换为符合条件(将根转移到第一个符合条件的地方)
        while (root -> val < low || root -> val > high) {
            if (root -> val < low) {
                root = root -> right;
            } else if (root -> val > high) {
                root = root -> left;
            } 
            if (root == nullptr) 
                break;
        }

        TreeNode* cur = root;
        // 处理左孩子小于low 的情况
        while (cur != nullptr) {
            while (cur -> left && cur -> left -> val < low) {
                cur -> left = cur -> left -> right;
            }
            cur = cur -> left;
        }
        
        cur = root;
        // 处理右孩大于high的情况
        while (cur != nullptr) {
            while (cur -> right && cur -> right -> val > high) {
                cur -> right = cur -> right -> left;
            }
            cur = cur -> right;
        }
        return root;
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