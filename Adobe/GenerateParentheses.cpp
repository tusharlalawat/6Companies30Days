#include<bits/stdc++.h>
using namespace std;

void solve(string temp, int open, int close, vector<string>& ans){
    if(open == 0 && close == 0){
        ans.push_back(temp);
        return;
    }

    if(open > 0) solve(temp+'(', open-1, close, ans);
    if(close > 0 && close > open) solve(temp+')', open, close-1, ans);
}

vector<string> AllParenthesis(int n) {
    vector<string> ans;
    solve("", n, n, ans);
    return ans;
}

int main() {
    int n;
    cin >>n;

    vector<string> ans = AllParenthesis(n);
    
    for(auto it : ans) cout <<it <<endl;
    return 0;
}