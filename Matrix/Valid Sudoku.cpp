class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board){
        vector<map<char,int>>row(9),col(9),block(9);

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){

                if(board[i][j]=='.'){
                    continue;
                }

                int blck=(i/3)*3+j/3;
                if(row[i].find(board[i][j])!=row[i].end() || col[j].find(board[i][j])!=col[j].end() || block[blck].find(board[i][j])!=block[blck].end()){
                    return false;
                }

                row[i][board[i][j]]++;
                col[j][board[i][j]]++;
                block[blck][board[i][j]]++;
            }
        }
        return true;
    }
};