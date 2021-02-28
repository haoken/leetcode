#include<iostream>
#include<vector>
#include<stack>
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
    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        stack<TreeNode*> nodeStack;
        nodeStack.push(root);
        TreeNode* previous = nullptr;
        while(!nodeStack.empty()) {
            TreeNode* node = nodeStack.top();
            nodeStack.pop();
            if (previous == nullptr) {// 头结点
                previous = node;
            } else {
                previous -> right = node;
                previous -> left = nullptr;
                previous = node;
            }

            if (node -> right != nullptr) {
                nodeStack.push(node -> right);
            }
            if (node -> left != nullptr) {
                nodeStack.push(node -> left);
            }
        }
    }
};

int main() {
    TreeNode* node = new TreeNode(1,new TreeNode(2,new TreeNode(3),new TreeNode(4)),new TreeNode(5,nullptr,new TreeNode(6)));
    Solution s;
    s.flatten(node);
    TreeNode* pres = node ;
    for (int i = 0; i < 6; i++) {
        cout << pres -> val << " -> ";
        pres = pres -> right;
    } 
}