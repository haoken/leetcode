#include<iostream>
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
        bool result = isOrder(root, (long long)INT_MAX + 1, (long long)INT_MIN - 1);
        return result;
    }

private:
    bool isOrder(TreeNode* root, long long max, long long min) { // 比较大小
        if (root == nullptr) {
            return true;
        }

        if (root -> val <= min || root -> val >= max) {
            return false;
        }


        bool left = isOrder(root -> left, root -> val, min);
        bool right = isOrder(root -> right, max, root -> val); 
        return left && right;
    }
};




int main() {
//     5
//    / \
//   1   4
//      / \
//     3   6
    // TreeNode node = TreeNode(5,new TreeNode(1),new TreeNode(4,new TreeNode(3),new TreeNode(6)));
    // TreeNode node = TreeNode(2,new TreeNode(1),new TreeNode(3)); 
    TreeNode node = TreeNode(INT_MIN);
    Solution s;
    bool result = s.isValidBST(&node);
    cout << result << endl;
    return 0;
}