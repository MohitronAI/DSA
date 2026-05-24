class Solution {
public:
    
    int count = 0;
    
    bool isSafe(vector<string>& board, int row, int col, int n) {
        
        // check column
        for(int i = 0; i < row; i++) {
            if(board[i][col] == 'Q')
                return false;
        }
        
        // upper left diagonal
        for(int i = row - 1, j = col - 1;
            i >= 0 && j >= 0;
            i--, j--) {
            
            if(board[i][j] == 'Q')
                return false;
        }
        
        // upper right diagonal
        for(int i = row - 1, j = col + 1;
            i >= 0 && j < n;
            i--, j++) {
            
            if(board[i][j] == 'Q')
                return false;
        }
        
        return true;
    }
    
    void backtrack(vector<string>& board, int row, int n) {
        
        // base case
        if(row == n) {
            count++;
            return;
        }
        
        for(int col = 0; col < n; col++) {
            
            if(isSafe(board, row, col, n)) {
                
                board[row][col] = 'Q';
                
                backtrack(board, row + 1, n);
                
                board[row][col] = '.';
            }
        }
    }
    
    int totalNQueens(int n) {
        
        vector<string> board(n, string(n, '.'));
        
        backtrack(board, 0, n);
        
        return count;
    }
};