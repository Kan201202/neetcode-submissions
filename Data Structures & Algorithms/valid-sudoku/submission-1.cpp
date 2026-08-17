class Solution {
public:
    bool checkrow(vector<vector<int>>& board, int i){
        bitset<10> b;
        for(int j=0;j<9;j++){
            if(board[i][j]==0) continue;
            if(b[board[i][j]] !=0) return false;
            else b[board[i][j]] = 1;
        }
        return true;
    }
    bool checkcol(vector<vector<int>>& board, int i){
        bitset<10> b;
        for(int j=0;j<9;j++){
            if(board[j][i]==0) continue;
            if(b[board[j][i]] !=0) return false;
            else b[board[j][i]] = 1;
        }
        return true;
    }
    bool checkbox(vector<vector<int>>& board, int i, int j){
        bitset<10>b;
        for(int m=0;m<3;m++){
            for(int n=0;n<3;n++){
                if(board[i+m][j+n]==0) continue;
                if(b[board[i+m][j+n]] !=0) return false;
                else b[board[i+m][j+n]] = 1;
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        bool ans=true;
        vector<vector<int>> newboard(9, vector<int>(9));
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] == '.') newboard[i][j] = 0;
                else newboard[i][j] = board[i][j] - '0';
            }
        }
        for(int i=0;i<9;i++){
            ans = checkrow(newboard,i);
            if(ans==false) return false;
        }

        for(int i=0;i<9;i++){
            ans = checkcol(newboard,i);
            if(ans==false) return false;
        }

        for(int i=0;i<9;i=i+3){
            for(int j=0;j<9;j=j+3){
                ans = checkbox(newboard,i,j);
                if(ans==false) return false;
            }
        }
        return ans;
    }
};
