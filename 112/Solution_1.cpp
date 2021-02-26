#include<iostream>
#include<vector>
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
    bool hasPathSum(TreeNode* root, int sum) {
        vector<int> sums = calPathSum(root);
        for (int i = 0; i < sums.size(); i++) {
            if (sums[i] == sum) {
                return true;
            }
        }
        return false;
    }

private:
    vector<int> calPathSum(TreeNode* root) {
        vector<int> pathSums;
        if (root == nullptr) {
            return pathSums;
        }

        if (root -> left == nullptr && root -> right == nullptr) {
            pathSums.push_back(root -> val);
            return pathSums;
        }

        vector<int> leftPathSums = calPathSum(root -> left);
        vector<int> rightPathSums = calPathSum(root -> right);


        for (int i = 0; i < leftPathSums.size(); i++) {
            pathSums.push_back(leftPathSums[i] + root -> val);
        }
        for (int i = 0; i<rightPathSums.size(); i++) {
            pathSums.push_back(rightPathSums[i] + root -> val);
        }
        return pathSums;
    }
};

        //       5
        //      / \
        //     4   8
        //    /   / \
        //   11  13  4
        //  /  \      \
        // 7    2      1


int main() {
    TreeNode* root = new TreeNode(5,
                                    new TreeNode(4,
                                                    new TreeNode(11, 
                                                                    new TreeNode(7), 
                                                                    new TreeNode(2)), 
                                                    nullptr), 
                                    new TreeNode(8,
                                                    new TreeNode(13),
                                                    new TreeNode(4, 
                                                                    nullptr, 
                                                                    new TreeNode(1)))
                                    );
    Solution solution;
    bool output =solution.hasPathSum(root,22);
    if (output) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}