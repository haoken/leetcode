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
        TreeNode* ans = NULL;
        while(root){
            if(root->val>p->val){ //p 在 root的左边 
                ans = root;
                root = root->left;
            }
            else root = root->right; // p 在 root的右边 或者 p就是root
        }
        return ans;
    }
};

int main() {
    TreeNode node = TreeNode(5, new TreeNode(3, new TreeNode(2), new TreeNode(4)), new TreeNode(6,nullptr,new TreeNode(7)));
    Solution s;
    TreeNode* next = s.inorderSuccessor(&node,node.left -> left);
    cout << next -> val;
    return 0;
}