class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> seen;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char val = board[i][j];
                if(val == '.') continue;
                if(seen.find(val) != seen.end()) return false;
                seen.insert(val);
            }
            seen.clear();
        }

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char val = board[j][i];
                if(val == '.') continue;
                if(seen.find(val) != seen.end()) return false;
                seen.insert(val);
            }
            seen.clear();
        }
        
        for(int row = 0; row < 9; row += 3){
            for(int col = 0; col < 9; col += 3){

                for(int i = row; i < row + 3; i++){
                    for(int j = col; j < col + 3; j++){
                        char val = board[i][j];
                        if(val == '.') continue;
                        if(seen.find(val) != seen.end()) return false;
                        seen.insert(val);
                    }
                }

                seen.clear();
            }
        }

        return true;
    }
};
