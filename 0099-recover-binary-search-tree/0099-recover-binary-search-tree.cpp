/**
 * Definition for a binary tree TreeNode.
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
    TreeNode * prev = nullptr;
    TreeNode* firstError = nullptr;
    TreeNode* secondError = nullptr;

    void helper(TreeNode* root)
    {
        if (!root)
            return ;
        
        helper(root->left);
        
        if (!firstError && prev && prev->val > root->val)
            firstError = prev;

        if (firstError && prev && prev->val > root->val)
            secondError = root;

        prev = root;

        helper(root->right);
    }

    void recoverTree(TreeNode* root) {
        helper(root);

        if (firstError and secondError)
        {
            int temp = firstError->val;
            firstError->val = secondError->val;
            secondError->val = temp;
        }
    }
};