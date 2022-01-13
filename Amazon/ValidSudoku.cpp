#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool isValidSudoku(int r, int c, int n, vector<vector<int>>& v){
        int row, col;
        for(int i=0; i<9; i++){
            if(i != r && v[i][c] == n) return false;
            if(i != c && v[r][i] == n) return false;
            
            row = 3*(r/3) + i/3;
            col = 3*(c/3) + i%3;
            
            if(row != r && col != c && v[row][col] == n) return false;
        }
        
        return true;
    }
    
    int isValid(vector<vector<int>> v){
        // code here
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(v[i][j] != 0){
                    if(isValidSudoku(i, j, v[i][j], v) == false) return 0;
                }
            }
        }
        return 1;
    }
};

int main() {
    return 0;
}