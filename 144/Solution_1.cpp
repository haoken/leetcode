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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root != nullptr){
            preorder(root, result);
        }
        return result;
    }
private:
    void preorder(TreeNode* root, vector<int>& result){
        if(root != nullptr){
            result.push_back(root->val);
            preorder(root->left, result);
            preorder(root->right, result);
        }else {
            return;
        }
    }
};

int main(){
    TreeNode root = TreeNode(1,
                            nullptr,new TreeNode(2,
                                        new TreeNode(3,nullptr,nullptr),nullptr));
    Solution solution;
    vector<int> result = solution.preorderTraversal(&root);
    for(int i = 0; i < result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl<<result.size();
}