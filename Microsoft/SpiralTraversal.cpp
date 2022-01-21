#include<bits/stdc++.h>
using namespace std;

vector<int> spirallyTraverse(vector<vector<int> > v, int n, int m){

    vector<int> ans;
    int r = 0, c = 0;

    while(r < n && c < m){                                     // Base Condition
        for(int i=c; i<m; i++) ans.push_back(v[r][i]);         // Traversing first row
        r++;

        for(int i=r; i<n; i++) ans.push_back(v[i][m-1]);       // Traversing last coloumn
        m--;

        if(r < n){
            for(int i=m-1; i>=c; i--) ans.push_back(v[n-1][i]);  // Traversing last row
            n--;
        }

        if(c < m){
            for(int i=n-1; i>=r; i--) ans.push_back(v[i][c]);      // Traversing first coloumn
            c++;
        }
    }

    return ans;
}
int main() {
    int n,m;
    cin >>n >>m;
    
    vector<vector<int>> v(n, vector<int> (m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cin >>v[i][j];
    }

    vector<int> ans = spirallyTraverse(v, n, m);

    cout <<"Ans: ";
    for(auto it : ans) cout <<it <<" ";
    cout <<endl;

    return 0;
}