class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left = maxDepth(root -> left);
        int right = maxDepth(root -> right);
        int length = left > right ? left + 1 : right + 1;
        return length;
    }
};