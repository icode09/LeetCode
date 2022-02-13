class Solution {
public:
    bool validEntry(vector<vector<char>>& board,char& ch,int i,int j){
        int row = i - i%3 , col = j - j%3;
        
        for(int x = 0;x<9;x++) if(board[x][j] == ch) return false;
        for(int x = 0;x<9;x++) if(board[i][x] == ch) return false;
        for(int x = 0;x<3;x++){
            for(int y = 0;y<3;y++){
                if(board[x+row][y+col] == ch) return false;
            }
        }
        
        return true;
    }
    bool sudoku(vector<vector<char>>& board,int i,int j){
        if(i == 9) return true;
        if(j == 9) return sudoku(board,i+1,0);
        
        if(board[i][j] != '.') return sudoku(board,i,j+1);
        
        for(char ch = '1' ; ch<='9';ch++){
            if(validEntry(board,ch,i,j)){
                board[i][j] = ch;
                if(sudoku(board,i,j+1)) return true;
                board[i][j] = '.';
            }
        }
        
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        sudoku(board,0,0);
    }
};