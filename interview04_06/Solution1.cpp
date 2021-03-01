#include<iostream>
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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root == nullptr || p == nullptr) {
            return nullptr;
        }

        stack<TreeNode*> nodeStack;
        TreeNode* pres = root;
        bool meet = false;
        while (pres != nullptr || !nodeStack.empty()) {
            while (pres != nullptr) {
                nodeStack.push(pres);
                pres = pres -> left;
            }
            
            pres = nodeStack.top();
            nodeStack.pop();
            if (meet) {//上一个是目标
                return pres;
            }

            if (pres == p) {
                meet = true;
            }

            pres = pres -> right;
        }
        return nullptr;
    }
};

int main() {
    TreeNode node = TreeNode(5, new TreeNode(3, new TreeNode(2), new TreeNode(4)), new TreeNode(6,nullptr,new TreeNode(7)));
    Solution s;
    TreeNode* next = s.inorderSuccessor(&node,node.left -> left);
    cout << next -> val;
    return 0;
}