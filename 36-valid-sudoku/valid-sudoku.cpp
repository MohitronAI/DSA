class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        unordered_set<string> seen;

        for(int row = 0; row < 9; row++) {
            for(int col = 0; col < 9; col++) {

                char num = board[row][col];

                if(num != '.') {

                    string rowKey = string(1, num) + " in row " + to_string(row);
                    string colKey = string(1, num) + " in col " + to_string(col);
                    string boxKey = string(1, num) + " in box " + 
                                    to_string(row/3) + "-" + to_string(col/3);

                    if(seen.count(rowKey) || 
                       seen.count(colKey) || 
                       seen.count(boxKey)) {
                        return false;
                    }

                    seen.insert(rowKey);
                    seen.insert(colKey);
                    seen.insert(boxKey);
                }
            }
        }

        return true;
    }
};