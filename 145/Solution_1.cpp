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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root != nullptr){
            postorder(root, result);
        }
        return result;
    }
private:
    void postorder(TreeNode* root, vector<int>& result){
        if(root != nullptr){
            postorder(root->left, result);
            postorder(root->right, result);
            result.push_back(root->val);
        }else {
            return;
        }
    }
};

int main(){
/*
    1
    |\
    * 2
      |\
      3 *
*/
    TreeNode root = TreeNode(1,
                            nullptr,new TreeNode(2,
                                        new TreeNode(3,nullptr,nullptr),nullptr));
    Solution solution;
    vector<int> result = solution.postorderTraversal(&root);
    for(int i = 0; i < result.size();i++){
        cout<<result[i]<<" ";
    }
}