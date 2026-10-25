class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> s;

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.')      continue;
                string row = to_string(board[i][j]) + "_ROW_" + to_string(i);
                string col = to_string(board[i][j]) + "_COL_" + to_string(j);
                string box = to_string(board[i][j]) + "_BOX_" + to_string(i/3) + '_' + to_string(j/3);

                if(s.find(row) != s.end() || s.find(col) != s.end() || s.find(box) != s.end())   return false;

                s.insert(row);
                s.insert(col);
                s.insert(box);
            }
        }
        return true;
    }
};
