#include<iostream>
#include<vector>

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
    vector<int> inorderTraversal(TreeNode* root) {//中序遍历
        vector<int> result;
        if(root == nullptr) return result;
        inorder(root, result);
        return result;
    }
private:
    void inorder(TreeNode* root, vector<int>& result) {
        if(root==nullptr) return ;
        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);
    }
};




int main(){
    TreeNode root = TreeNode(1,
                            nullptr,new TreeNode(2,
                                        new TreeNode(3,nullptr,nullptr),nullptr));
    Solution solution;
    vector<int> result = solution.inorderTraversal(&root);
    for(int i = 0; i < result.size();i++){
        cout<<result[i]<<" ";
    }
}