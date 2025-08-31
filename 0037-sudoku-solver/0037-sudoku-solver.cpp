class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (int digit = 1; digit <= 9; digit++) {
                        if (check(board, i, j, digit)) {
                            board[i][j] = digit + '0'; // ✅ fix
                            if (solve(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false; // ✅ after loop
                }
            }
        }
        return true;
    }

    bool check(vector<vector<char>>& board, int r, int c, int digit) {
        int nr = (r / 3) * 3;
        int nc = (c / 3) * 3;
        char ch = digit + '0'; // ✅ fix

        for (int i = 0; i < 9; i++) {
            if (board[r][i] == ch || board[i][c] == ch) return false;
            if (board[nr + i / 3][nc + i % 3] == ch) return false;
        }
        return true;
    }
};
