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

class Path {
public:
    vector<int> path;
    int sum;
};

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        statPaths(root);
        int count = 0;
        vector<Path> targetPaths;
        for (int i = 0; i < allPaths.size(); i++) {
            if (allPaths[i].sum == sum) {
                count++;
                addToPaths(targetPaths, allPaths[i].path, sum);
            }
        }

        for (int i = 0; i < targetPaths.size(); i++) {
            for (int j = 0; j < targetPaths[i].path.size(); j++) {
                cout << targetPaths[i].path[j] << " ";
            }
            cout << endl;
        }
        return count;
    }

private:
    vector<Path> allPaths;
    vector<Path> statPaths(TreeNode* root) {
        vector<Path> result;
        if (root == nullptr) {
            return result;
        }
        
        addToPaths(allPaths, {root -> val}, root -> val);

        if (root-> left == nullptr && root -> right == nullptr) {
            addToPaths(result, {root -> val}, root -> val);
            return result;
        }

        vector<Path> leftPaths = statPaths(root -> left);
        vector<Path> rightPaths = statPaths(root -> right);

        for (int i = 0; i < leftPaths.size(); ++i) {
            leftPaths[i].path.insert(leftPaths[i].path.begin(), root -> val);
            addToPaths(result, leftPaths[i].path, leftPaths[i].sum + root -> val);
            addToPaths(allPaths, leftPaths[i].path, leftPaths[i].sum + root -> val);
        }
        for (int i = 0; i < rightPaths.size(); ++i) {
            rightPaths[i].path.insert(rightPaths[i].path.begin(), root -> val);
            addToPaths(result, rightPaths[i].path, rightPaths[i].sum + root -> val);
            addToPaths(allPaths, rightPaths[i].path, rightPaths[i].sum + root -> val);
        }
        return result;
    }

    void addToPaths(vector<Path>& paths, vector<int> path, int sum) {
        Path p;
        p.path = path;
        p.sum = sum;
        paths.push_back(p);
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
    TreeNode* root = new TreeNode(5,
                                    new TreeNode(4,
                                                    new TreeNode(11, 
                                                                    new TreeNode(7), 
                                                                    new TreeNode(2)), 
                                                    nullptr), 
                                    new TreeNode(8,
                                                    new TreeNode(13),
                                                    new TreeNode(4, 
                                                                    new TreeNode(5), 
                                                                    new TreeNode(1)))
                                    );
    // TreeNode* root = new TreeNode(1,new TreeNode(2),nullptr);
    Solution solution;
    int num = solution.pathSum(root,22);
    cout << num << endl;
    return 0;
}