class Solution {
public:
    bool isValid(vector<vector<char>> &board, char dig, int row, int col)
    {
        for (int i = 0; i < 9; i++)
            if (board[row][i] == dig) return false;

        for (int i = 0; i < 9; i++)
            if (board[i][col] == dig) return false;

        int sr = (row / 3) * 3;
        int sc = (col / 3) * 3;
        
        for (int i = sr; i < sr + 3; i++)
            for (int j = sc; j < sc + 3; j++)
                if (board[i][j] == dig) return false;

        return true;
    }

    bool solver(vector<vector<char>> &board, int row, int col)
    {
        int nextRow = row;
        int nextCol = col + 1;

        if (nextCol == 9)
        {
            nextRow = row + 1;
            nextCol = 0;
        }

        if (row == 9) return true;

        if (board[row][col] != '.')
            return solver(board, nextRow, nextCol);

        for (char dig = '1'; dig <= '9'; dig++)
        {
            if (isValid(board, dig, row, col))
            {
                board[row][col] = dig;
                if (solver(board, nextRow, nextCol))
                    return true;
                board[row][col] = '.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solver(board, 0, 0);
    }
};