class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int row = -1, s, e;

        for (int i = 0; i < m; i++)
        {
            int n = matrix[i].size();

            if (target <= matrix[i][n - 1])
            {
                s = 0, 
                e = n - 1;
                row = i;

                break;
            }
        }

        if (row == -1) return false;

        while (s <= e)
        {
            int m = (s + e) / 2;

            if (matrix[row][m] == target)
            {
                return true;
            }

            else if (matrix[row][m] > target)
            {
                e = m - 1;
            }

            else
            {
                s = m + 1;
            }
        }

        return false;
    }
};