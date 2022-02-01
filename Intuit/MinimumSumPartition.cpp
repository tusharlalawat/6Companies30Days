#include<bits/stdc++.h>
using namespace std;

int minDifference(vector<int> v, int n) {

    int sum = 0;
    for(int i=0; i<n; i++) sum += v[i];

    vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
    for(int i=0; i<=n; i++) dp[i][0] = true;
    for(int i=1; i<=sum; i++) dp[0][i] = false;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            dp[i][j] = dp[i-1][j];
            if(v[i-1] <= j) {
                dp[i][j] = (dp[i][j] || dp[i-1][j - v[i-1]]);
            }
        }
    }

    for(int i=sum/2; i>=0; i--){
        if(dp[n][i] == true) return (sum - 2*i);
    }

    return -1;
}
int main() {

    int n;
    cin >>n;

    vector<int> v(n);
    for(auto &i : v) cin >>i;

    cout <<"Ans: " <<minDifference(v, n) <<endl;
    return 0;
}