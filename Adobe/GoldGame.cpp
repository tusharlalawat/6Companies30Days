#include<bits/stdc++.h>
using namespace std;

int solve(int l, int r, vector<int>& v, vector<vector<int>>& dp){
    if(l == r) return v[l];
    if(l > r) return 0;

    if(dp[l][r] != -1) return dp[l][r];

    // initially v[l...r], now if we take v[l] than the array will be v[l+1..r] so the 2nd player will have to options, and we have to minimize his/her profit
    int a = v[l] + min(solve(l+2, r, v, dp), solve(l+1, r-1, v, dp));
    int b = v[r] + min(solve(l+1, r-1, v, dp), solve(l, r-2, v, dp));

    dp[l][r] = max(a, b);
    return dp[l][r];
}

int maxCoins(vector<int>& v, int n){

    int l = 0, r = n-1;
    vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
    return solve(l, r, v, dp);
}

int main() {
    int n;
    cin >>n;

    vector<int> v(n);
    for(int i=0; i<n; i++) cin >>v[i];

    cout <<"No. of max coins: " <<maxCoins(v, n) <<endl;
    return 0;
}