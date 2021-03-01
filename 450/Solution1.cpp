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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return root;
        }

        if (root -> val == key) {
            if (root -> left == nullptr && root -> right == nullptr) {
                return nullptr;
            } else if (root -> left == nullptr) {
                return root -> right;
            } else if (root -> right == nullptr) {
                return root -> left;
            } else {
                TreeNode* node = root -> right;
                while (node -> left != nullptr) {
                    node = node -> left;
                }
                node -> left = root -> left;
                return root -> right;
            }
        }

        TreeNode* pres = root ;
        TreeNode* previous = nullptr;
        bool leftFlag = false;
        while (pres != nullptr) {
            if (pres -> val > key) {
                leftFlag = true;
                previous = pres;
                pres = pres -> left;
            } else if (pres -> val < key) {
                leftFlag = false;
                previous = pres; 
                pres = pres -> right;
            } else { //找到该节点
                if (pres -> left == nullptr && pres -> right == nullptr) {//该节点没有孩子。直接删除
                    leftFlag ? previous -> left = nullptr : previous -> right = nullptr;
                } else if (pres -> left != nullptr && pres -> right == nullptr) {//该节点只有左孩子，则直接补上空位
                    leftFlag ? previous -> left = pres -> left : previous -> right = pres -> left;
                } else if (pres -> left == nullptr && pres -> right != nullptr) { // 该节点只有右孩子，则直接补上空位
                    leftFlag ? previous -> left = pres -> right : previous -> right = pres -> right;
                } else if (pres -> left != nullptr && pres -> right != nullptr) { // 该节点有左右孩子，则右孩子的根补上，左子树插入到右子树的最左边。
                    TreeNode* node = pres -> right;
                    while (node -> left != nullptr) {
                        node = node -> left;
                    }
                    node -> left = pres -> left;
                    leftFlag? previous -> left = pres -> right : previous -> right = pres -> right; 
                }
                break;
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