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
    TreeNode* helper(vector<int> &preorder, int bound, int& idx)
    {

        if (idx >= preorder.size() || preorder[idx] > bound)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[idx]);
        idx++;

        root->left = helper(preorder, root->val, idx);
        root->right = helper(preorder, bound, idx);

        return root;

    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return helper(preorder, INT_MAX, i);
    }
};