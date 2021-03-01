#include<iostream>
#include<string>
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
    TreeNode* deleteNode(TreeNode* root, int key) { //功能 ： 删除key节点,返回根节点
        if (root == nullptr) {
            return nullptr;
        }

        if (key < root -> val) {
            root -> left = deleteNode(root -> left, key);
        } else if (key > root -> val) {
            root -> right = deleteNode(root -> right, key);
        } else {
            if (!root -> left) { //删除节点没有左孩子
                return root -> right;
            } else if (!root -> right) { //删除节点灭有右孩子
                return root -> left;
            } else { // 有左右孩子
                TreeNode* node = root -> right;
                while (node -> left != nullptr) {
                    node = node -> left;
                }
                node -> left = root -> left;
                return root -> right;
            }
        }
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

int main () {
    TreeNode node = TreeNode(5, new TreeNode(3, new TreeNode(2), new TreeNode(4)), new TreeNode(6,nullptr,new TreeNode(7)));
    Solution s;
    s.deleteNode(&node, 3);
    breadthFirstSearch(&node);
}
