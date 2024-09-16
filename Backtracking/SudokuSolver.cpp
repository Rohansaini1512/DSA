#include<bits/stdc++.h>
using namespace std;

bool canWePlace(vector<vector<char>>& board , int row , int col , int num){
    for(int j = 0 ; j < 9 ; j++){
        if(board[row][j] == num) return false;
    }  
    for(int i = 0 ; i < 9 ; i++){
        if(board[i][col] == num) return false;
    }
    int r = (row/3)*3;
    int c = (col/3)*3;
    for(int i = r ; i < (r+3) ; i++){
        for(int j = c ; j < (c+3) ; j++){
            if(board[i][j] == num) return false;
        }
    }
    return true;
}

bool sudoku(vector<vector<char>>& board , int row , int col){
    if(col == 9) return sudoku(board , row+1 , 0);
    if(row == 9) return true;
    if(board[row][col] == '.'){
        for(int num = 1 ; num <= 9 ; num++){
            if(canWePlace(board , row, col , '0'+num)){
                board[row][col] = '0'+num;
                bool res = sudoku(board , row , col + 1);
                if(res) return true;
                board[row][col] = '.';
            }
        }
        return false;
    }else{
        return sudoku(board , row , col +1);
    }
}

int main(){
    vector<vector<char>> board[9][9];
    for(int i = 0 ; i < 9 ; i++){
        for(int j = 0 ; j < 9 ; j++){
            cin>>board[i][j];
        }
    }
    sudoku(board , 0 , 0);
    return 0;
}
