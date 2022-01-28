#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll mod = 1e9+7;

int kvowelwords(int n, int k) {
    vector<vector<ll>> dp(n+1, vector<ll>(k+1, 0));

    for(int i=0; i<=n; i++){
        for(int j=0; j<=k; j++){
            if(i == 0) dp[i][j] = 1;
            else {
                dp[i][j] = dp[i-1][k]*21%mod;
                if(j > 0) dp[i][j] = (dp[i][j] + dp[i-1][j-1]*5%mod)%mod;
            }
        }
    }
    return dp[n][k];
}

int main() {
    int n, k;
    cin >>n >>k;

    cout <<"No. of distinct words are: " <<kvowelwords(n, k) <<endl;
    return 0;
}