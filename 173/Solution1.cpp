#include<iostream>
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


class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        //初始化的时候完成中序排列的第一个步骤
        //需要保证next调用时栈顶元素始终是最小的元素。
        TreeNode* pres = root;
        while (pres != nullptr) {
            nodeStack.push(pres);
            pres = pres -> left;
        }
    }
    
    int next() {
        TreeNode* node = nodeStack.top();
        nodeStack.pop();
        int val = node -> val;
        //每个得到处理的节点，左边节点都全部处理完了，开始处理右边节点。
        if (node -> right != nullptr){
            node = node -> right;
            while (node) {
                nodeStack.push(node);
                node = node -> left;
            }
        }
        return val;
    }
    
    bool hasNext() {
        return !nodeStack.empty();
    }

private:
    stack<TreeNode*> nodeStack;

};

int main () {
    TreeNode node = TreeNode(5, new TreeNode(3, new TreeNode(2), new TreeNode(4)), new TreeNode(6,nullptr,new TreeNode(7)));
    BSTIterator* iterator = new BSTIterator(&node);
    while (iterator -> hasNext()) {
        cout << iterator -> next() << " ";
    }
}

