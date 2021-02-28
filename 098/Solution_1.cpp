#include<iostream>
#include<vector>
#include<stack>
#include<climits>
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
    bool isValidBST(TreeNode* root) {
        return inOrderTravers(root);
    }

private:
    bool inOrderTravers(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        long long lastVal = (long long)INT_MIN - 1;
        stack<TreeNode*> nodeStack;
        TreeNode* pres = root;
        while (pres != nullptr || !nodeStack.empty()) {
            while (pres != nullptr) {
                nodeStack.push(pres);
                pres = pres -> left;
            }

            pres = nodeStack.top();
            nodeStack.pop();
            if (pres -> val <= lastVal) {
                return false;
            }
            lastVal = pres -> val;
            pres = pres -> right;
        } 
        return true;
    }
};

int main() {
//     5
//    / \
//   1   4
//      / \
//     3   6
    TreeNode node = TreeNode(5,new TreeNode(1),new TreeNode(4,new TreeNode(3),new TreeNode(6)));
    // TreeNode node = TreeNode(2,new TreeNode(1),new TreeNode(3)); 
    Solution s;
    bool result = s.isValidBST(&node);
    cout << result << endl;
    return 0;
}