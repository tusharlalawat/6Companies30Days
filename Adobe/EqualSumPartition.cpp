#include<bits/stdc++.h>
using namespace std;

bool equalPartition(int n, vector<int>& v){

    int sum = 0;
    for(int i=0; i<n; i++) sum += v[i];

    if(sum%2 == 1) return false;

    vector< vector<bool> > dp(n+1, vector<bool>(sum/2+1, false));
    for(int i=0; i<=n; i++) dp[i][0] = true;
    for(int i=1; i<=sum/2; i++) dp[0][i] = false;

    for(int i=1; i<=n; i++){
        for(int j=i; j<=sum/2; j++){
            dp[i][j] = dp[i-1][j];        // If we does not include the current item in our subset

            if(v[i-1] <= j) {
                dp[i][j] = dp[i][j] || dp[i-1][j - v[i-1]];
            }
        }
    }

    return dp[n][sum/2];
}

int main() {
    int n;
    cin >>n;

    vector<int> v(n);
    for(auto &i : v) cin >>i;

    cout <<equalPartition(n, v) <<endl;
    return 0;
}