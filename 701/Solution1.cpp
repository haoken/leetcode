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

class ResultType{
public:
    TreeNode* node;
    bool leftFlag;
    
    ResultType() {
        node = nullptr;
        leftFlag = false;
    }

    ResultType(TreeNode* _node, bool _leftFlag) {
        node = _node;
        leftFlag = _leftFlag;
    }
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }

        ResultType insertPos = findInsertPos(root ,val);
        if (insertPos.leftFlag) {
            insertPos.node -> left = new TreeNode(val);
        } else {
            insertPos.node -> right = new TreeNode(val);
        }

        return root;
    }

private:
    ResultType findInsertPos(TreeNode* root, int val) {

        if (val < root -> val && root -> left == nullptr) {
            return ResultType(root, true); 
        } else if (val > root -> val && root -> right == nullptr) {
            return ResultType(root,false);
        }

        ResultType insertPos;

        if (val < root -> val) { //在左边
            insertPos = findInsertPos(root -> left, val);
        } else { // 在右边
            insertPos = findInsertPos(root -> right, val);
        }
        
        return insertPos;
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