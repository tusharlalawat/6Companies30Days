#include<bits/stdc++.h>
using namespace std;

bool isFound(int r, int c, int ind, int n, int m, vector<vector<char>>& v, string s) {
    if(ind == s.length()) return true;
    if(r < 0 || r >= n || c < 0 || c >= m) return false;
    if(v[r][c] != s[ind]) return false;

    // Very important
    char temp = v[r][c];
    v[r][c] = '?';

    if(isFound(r, c+1, ind+1, n, m, v, s)) return true;
    else if(isFound(r, c-1, ind+1, n, m, v, s)) return true;
    else if(isFound(r+1, c, ind+1, n, m, v, s)) return true;
    else if(isFound(r-1, c, ind+1, n, m, v, s)) return true;

    v[r][c] = temp;
    return false;
}

bool isWordExist(vector<vector<char>>& v, string s) {

    int n = v.size();
    int m = v[0].size();

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(isFound(i, j, 0, n, m, v, s)) return true;
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >>n >>m;

    vector<vector<char>> v(n, vector<char>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            cin >>v[i][j];
    }

    string s;
    cin >>s;

    cout <<isWordExist(v, s) <<endl;
    return 0;
}

