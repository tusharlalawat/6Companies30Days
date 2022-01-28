#include<bits/stdc++.h>
using namespace std;

int longestArithSeqLength(vector<int>& v) {

    int n = v.size();
    if(n <= 2) return n;

    int ans = 2;
    vector< vector<int> > dp(n, vector<int>(2000, 0));
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int diff = v[j] - v[i] + 1000;

            dp[j][diff] = max(2, dp[i][diff]+1);
            ans = max(ans, dp[j][diff]);
        }
    }

    return ans;
}

int main(){
    int n;
    cin >>n;

    vector<int> v(n);
    for(auto &it : v) cin >>it;
}