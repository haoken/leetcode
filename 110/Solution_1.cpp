#include<iostream>
#include<vector>
#include<cmath>

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
    bool isBalanced(TreeNode* root) {
        return maxDepth(root) != NOT_BALANCED;
    }

private:
    const int NOT_BALANCED = -1;
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int left = maxDepth(root -> left);
        int right = maxDepth(root -> right);

        if (left == NOT_BALANCED || right == NOT_BALANCED || abs(left - right) > 1) {
            return NOT_BALANCED;
        }
        
        return left >= right ? left + 1 : right + 1;
    }
};

int main() {
    // 1
    //  \
    //   2
    //  /
    // 3
    TreeNode root = TreeNode(1,
                            nullptr,new TreeNode(2,
                                        new TreeNode(3,nullptr,nullptr),nullptr));
    Solution solution;
    bool result = solution.isBalanced(&root);
    cout << result;
    return 0;
}