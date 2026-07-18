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
    int searchIdx(vector<int>& inorder, int val, int left, int right)
    {
        for (int i = left; i <= right; i++)
        {
            if (inorder[i] == val)
                return i;
        }

        return -1;
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& preIdx, int left, int right) {
        if (left > right) return nullptr;

        int nodeVal = preorder[preIdx];
        TreeNode* root = new TreeNode(nodeVal);
        preIdx++;

        int inIdx = searchIdx(inorder, nodeVal, left, right);

        root->left = build(preorder, inorder, preIdx, left, inIdx - 1);
        root->right = build(preorder, inorder, preIdx, inIdx + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int left = 0, right = inorder.size() - 1;
        int idx = 0;

        return build(preorder, inorder, idx, left, right);
    }
};