class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++)
        {
            unordered_map<char, int> m;

            for (int j = 0; j < board.size(); j++)
            {
                if (board[i][j] != '.')
                {
                    if (m[board[i][j]] >= 1)
                        return false;
                    else
                        m[board[i][j]]++;
                }
            }
        }

        for (int i = 0; i < board.size(); i++)
        {
            unordered_map<char, int> m;

            for (int j = 0; j < board.size(); j++)
            {
                if (board[j][i] != '.')
                {
                    if (m[board[j][i]] >= 1)
                        return false;
                    else
                        m[board[j][i]]++;
                }
            }
        }

        for (int box = 0; box < 9; box++) {
            unordered_map<char, int> m;
            
            int row_start = (box / 3) * 3;
            int col_start = (box % 3) * 3;

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    char val = board[row_start + i][col_start + j];

                    if (val != '.') {
                        if (m[val] >= 1) {
                            return false;
                        }
                        m[val]++;
                    }
                }
            }
        }

        return true;
        
    }
};