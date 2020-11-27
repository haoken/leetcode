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
    vector<int> inorderTraversal(TreeNode* root) {//中序遍历
        vector<int> result;
        if(root == nullptr) return result;
        stack<TreeNode*> stk;
        TreeNode* node = root;
        while(!stk.empty()||node!= nullptr) {
            while(node!= nullptr){//找到左孩子为空的结点
                stk.emplace(node);
                node = node -> left;
            }
            node = stk.top();
            result.push_back(node->val);
            stk.pop();//根执行后就无需再用，直接出栈
            node = node -> right;
        }
        return result;
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
    vector<int> result = solution.inorderTraversal(&root);
    for(int i = 0; i < result.size();i++){
        cout<<result[i]<<" ";
    }
}