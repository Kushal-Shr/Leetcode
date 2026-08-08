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
    void buildArr(TreeNode* root, vector<int> &arr)
    {
        if (!root)
            return ;

        buildArr(root->left, arr);
        arr.push_back(root->val);
        buildArr(root->right, arr);
    }

    int minDiffInBST(TreeNode* root) {
        vector<int> arr;

        buildArr(root, arr);

        int minDiff = 1e7;

        for (int i = 1; i < arr.size(); i++)
            minDiff = min(minDiff, arr[i] - arr[i - 1]);

        return minDiff;
    }
};