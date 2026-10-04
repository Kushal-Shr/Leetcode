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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if (!root)
            return ans;

        queue<TreeNode *> q;
        q.push(root);
        q.push(nullptr);

        vector<int> temp;

        while (q.size() > 0)
        {
            TreeNode* ele = q.front();
            q.pop();

            if (ele)
            {   
                temp.push_back(ele->val);

                if (ele->left)
                    q.push(ele->left);
                if (ele->right)
                    q.push(ele->right);
            }

            else
            {
                ans.push_back(temp);
                temp.clear();

                if (q.size() > 0)
                    q.push(nullptr);
            }
        }

        return ans;
    }
};
