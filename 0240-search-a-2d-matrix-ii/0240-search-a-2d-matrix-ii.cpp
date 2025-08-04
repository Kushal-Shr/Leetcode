class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row = matrix.size();
        int col = matrix[0].size();

        int row_idx = 0, col_idx = col - 1;

        while (row_idx < row && col_idx >= 0)
        {
            int ele = matrix[row_idx][col_idx];

            if (target == ele)
                return true;

            else if (target > ele)
                row_idx++;
            
            else 
                col_idx--;
        }

        return false;
    }
};