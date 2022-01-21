#include<bits/stdc++.h>
using namespace std;

int solve(int r, int c, int n, int m, vector<vector<int>>& v){
    if(r<0 || r>=n || c<0 || c>=m || v[r][c] == 0) return 0;
    
    v[r][c] = 0; // Making Visited
    
    int a = solve(r-1, c, n, m, v);
    int b = solve(r+1, c, n, m, v);
    int d = solve(r, c-1, n, m, v);
    int e = solve(r, c+1, n, m, v);
    int f = solve(r-1, c-1, n, m, v);
    int g = solve(r-1, c+1, n, m, v);
    int h = solve(r+1, c-1, n, m, v);
    int i = solve(r+1, c+1, n, m, v);
    
    return (1 + a + b + d + e + f + g + h + i);
}
int findMaxArea(vector<vector<int>>& v) {
    // Code here
    int n = v.size(), m = v[0].size();
    int sum = 0;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            if(v[i][j] == 1) sum = max(sum, solve(i, j, n, m, v));
    }
    
    return sum;
}

int main(){
    return 0;
}