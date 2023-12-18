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
    void getInorderVal(TreeNode* node, vector<int>& result) {
        if (node == nullptr) return;
        
        getInorderVal(node->left, result);
        result.push_back(node->val);
        getInorderVal(node->right, result);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        
        vector<int> result;
        getInorderVal(root, result);
        
        return result;
    }
};

