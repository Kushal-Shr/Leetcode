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
    void helper(TreeNode* root, string path, vector<string> &paths)
    {
        if (!root->left && !root->right)
        {
            paths.push_back(path);
            return;
        }

        if (root->left)
            helper(root->left, path + "->" + to_string(root->left->val), paths);
        if (root->right)
            helper(root->right, path + "->" + to_string(root->right->val), paths);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        string path = to_string(root->val);
        vector<string> paths;

        helper(root, path, paths);

        return paths;
    }
};