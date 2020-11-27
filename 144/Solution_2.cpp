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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == nullptr) return result;
        stack<TreeNode*> stk;
        TreeNode* node = root;
        while(!stk.empty() || node != nullptr) {
            while(node != nullptr){
                result.emplace_back(node->val);
                stk.emplace(node);
                node = node->left;//一直往左遍历直到某个结点的左孩子为空
            }
            //如果某个结点左孩子为空，则出栈，遍历右子树
            node = stk.top();
            stk.pop();
            node = node->right;
            //如果右子树也为空，则该子树遍历完，注意回溯上面的未遍历右子树的祖先结点（这些结点都在栈中）。如果回溯完了node未空，则遍历完成
        }
        return result;
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
}