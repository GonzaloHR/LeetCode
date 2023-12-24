/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void traversal(TreeNode* root, int targetSum, int curSum, 
    vector<int>& curPath, vector<vector<int>>& paths) {
        if (!root)
            return;
        curPath.push_back(root->val);    
        if (!root->left && !root->right) {
            if (targetSum == (curSum + root->val)) 
                paths.push_back(curPath);
        }
        traversal(root->left, targetSum, curSum + root->val, curPath, paths);
        traversal(root->right, targetSum, curSum + root->val, curPath, paths);
        curPath.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> paths;
        vector<int> curPath;
        int curSum = 0;
        traversal(root, targetSum, curSum, curPath, paths);

        return paths;
    }
};