class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;

                if(!check(board, i, j, board[i][j])) {
                    return false;
                }
            }
        }
        return true;
    }

    bool check(vector<vector<char>>& board, int r, int c, char digit) {
        // check row and column
        for(int k = 0; k < 9; k++) {
            if(k != c && board[r][k] == digit) return false; // row
            if(k != r && board[k][c] == digit) return false; // col
        }

        // check 3x3 box
        int boxRow = (r / 3) * 3;
        int boxCol = (c / 3) * 3;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                int nr = boxRow + i;
                int nc = boxCol + j;
                if((nr != r || nc != c) && board[nr][nc] == digit) {
                    return false;
                }
            }
        }
        return true;
    }
};
