#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class ResultType {
public:
    vector<string> paths;
    vector<int> pathLengths;
    ResultType() {}
    ResultType(vector<string> paths, vector<int> pathLengths) : paths(paths), pathLengths(pathLengths) {}
};

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        ResultType result = statPaths(root, sum);
        // for (int i = 0; i < targetPaths.paths.size(); i++) {
        //     cout << targetPaths.paths[i] << endl;
        // }
        return targetPaths.pathLengths.size();
    }

private:
    ResultType targetPaths;
    ResultType statPaths(TreeNode* root, int target) {
        ResultType result;
        if (root == nullptr) {
            result.paths.push_back("");
            result.pathLengths.push_back(0);
            return result;
        }

        string curVal = to_string(root -> val);

        if (root -> left == nullptr && root -> right == nullptr) {
            result.paths.push_back(curVal);
            result.pathLengths.push_back(root -> val);
            if (root -> val == target) {
                targetPaths.paths.push_back(curVal);
                targetPaths.pathLengths.push_back(root -> val);
            }
            return result;
        } 

        ResultType leftPaths = statPaths(root -> left, target);
        ResultType rightPaths = statPaths(root -> right, target);


        for (int i = 0; i < leftPaths.paths.size(); ++i) {
            result.paths.push_back(curVal + "->" + leftPaths.paths[i]);
            result.pathLengths.push_back(root -> val + leftPaths.pathLengths[i]);
            if (root -> val + leftPaths.pathLengths[i] == target) {
                targetPaths.paths.push_back(curVal + "->" + leftPaths.paths[i]);
                targetPaths.pathLengths.push_back(root -> val + leftPaths.pathLengths[i]);
            }
        }
        for (int i = 0; i < rightPaths.paths.size(); i++) {
            result.paths.push_back(curVal + "->" + rightPaths.paths[i]);
            result.pathLengths.push_back(root -> val + rightPaths.pathLengths[i]);
            if (root -> val + rightPaths.pathLengths[i] == target) {
                targetPaths.paths.push_back(curVal + "->" + rightPaths.paths[i]);
                targetPaths.pathLengths.push_back(root -> val + rightPaths.pathLengths[i]);
            }
        }
        return result;
    }
};

        //       5
        //      / \
        //     4   8
        //    /   / \
        //   11  13  4
        //  /  \    / \
        // 7    2  5   1

int main() {
    // TreeNode* root = new TreeNode(5,
    //                                 new TreeNode(4,
    //                                                 new TreeNode(11, 
    //                                                                 new TreeNode(7), 
    //                                                                 new TreeNode(2)), 
    //                                                 nullptr), 
    //                                 new TreeNode(8,
    //                                                 new TreeNode(13),
    //                                                 new TreeNode(4, 
    //                                                                 new TreeNode(5), 
    //                                                                 new TreeNode(1)))
    //                                 );
    TreeNode* root = new TreeNode(1,new TreeNode(2),nullptr);
    Solution solution;
    int num = solution.pathSum(root,1);
    cout << num << endl;
    return 0;
}