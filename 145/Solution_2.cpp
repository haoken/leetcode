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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == nullptr) return result;
        stack<TreeNode*> stk;
        TreeNode* node = root;
        TreeNode* prev = nullptr;
        while(node != nullptr||!stk.empty()) {
            while(node != nullptr){//找到某个左孩子为空的结点
                stk.emplace(node);
                node = node->left;
            }
            node = stk.top();//出栈检查该结点右孩子是否为空，如果为空则输出，不为空则重新入栈。
            stk.pop();      
            if(node->right==nullptr||node->right==prev){//右孩子为空 或者 右孩子为上次执行的
                result.push_back(node->val);
                prev = node;
                node = nullptr; 
            }
            else{//右孩子不为空
                stk.emplace(node);
                node = node->right;
            }
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
    vector<int> result = solution.postorderTraversal(&root);
    for(int i = 0; i < result.size();i++){
        cout<<result[i]<<" ";
    }
}