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
        lastPoint(root);
    }

private:
    TreeNode* lastPoint(TreeNode* root) { // 返回最后一个节点
        if (root == nullptr) {
            return root ;
        }

        TreeNode* left = lastPoint(root -> left);
        TreeNode* right = lastPoint(root -> right);
        
        if (left != nullptr) {
            left -> right = root -> right;
            root -> right = root -> left;
            root -> left = nullptr;
        } 
        
        if (right != nullptr) {
            return right;
        } else if (left != nullptr) {
            return left;
        } else {
            return root;
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