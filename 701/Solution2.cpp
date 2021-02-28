#include<iostream>
#include<vector>
#include<stack>
#include<queue>
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        if(root->val < val) root->right = insertIntoBST(root->right,val);
        if(root->val > val) root->left = insertIntoBST(root->left,val);
        return root;
    }
};

void breadthFirstSearch(TreeNode* root){ // 广度优先BFS
    queue<TreeNode *> nodeQueue;  
    nodeQueue.push(root);
    TreeNode *node;
    while (!nodeQueue.empty()) {
        node = nodeQueue.front();
        nodeQueue.pop();
        cout << node -> val << " ";//遍历根结点
        if (node -> left) {
            nodeQueue.push(node -> left);  //先将左子树入队
        }
        if (node -> right) {
            nodeQueue.push(node -> right);  //再将右子树入队
        }
    }
}

int main() {
    TreeNode node = TreeNode(4,new TreeNode(2,new TreeNode(1),new TreeNode(3)),new TreeNode(7));
    breadthFirstSearch(&node);
    cout << endl;
    Solution s;
    s.insertIntoBST(&node, 5);
    breadthFirstSearch(&node);
}