class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int sRow = 0, eRow = m - 1, sCol = 0, eCol = n - 1;
        vector<int> ans;

        while (sRow <= eRow && sCol <= eCol)
        {
            
            for (int i = sCol; i <= eCol; i++)
                ans.push_back(matrix[sRow][i]);
            sRow++;

            for (int i = sRow; i <= eRow; i++)
                ans.push_back(matrix[i][eCol]);
            eCol--;

            if (sRow <= eRow) { 
                for (int i = eCol; i >=sCol; i--) 
                    ans.push_back(matrix[eRow][i]);
                eRow--;
            }

            if (sCol <= eCol)
            {
                for (int i = eRow; i >= sRow; i--)
                    ans.push_back(matrix[i][sCol]);
                sCol++;
            }
        }

        return ans;
    }
};