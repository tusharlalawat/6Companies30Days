#include<bits/stdc++.h>
using namespace std;

long long mod = 1e9 + 1;
int solve(int n, int x, int i, long long dp[][1001]){

    // Base Conditions
    if(n == 0) return 1;
    if(n < i) return 0;
    if(dp[i][n] != -1) return dp[i][n];

    long long temp = pow(i, x);
    if(temp <= n){
        dp[i][n] = solve(n, x, i+1, dp) + solve(n-temp, x, i+1, dp);
        dp[i][n] %= mod;
    } else {
        dp[i][n] = 0;
        dp[i][n] %= mod;
    }
    return dp[i][n];
}

int numOfWays(int n, int x) {
    long long dp[1001][1001];
    memset(dp, -1, sizeof(dp));

    int i = 1;
    return solve(n, x, i, dp);
}

int main() {
    int n, x;
    cin >>n >>x;

    cout <<"Number of ways: " <<numOfWays(n, x) <<endl;
    return 0;
}