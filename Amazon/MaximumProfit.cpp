#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
        // code here
        int dp[K+1][N];
        for(int i=0; i<=K; i++) dp[i][0]=0;
        for(int i=0; i<N; i++) dp[0][i]=0;

        for(int i=1; i<=K; i++)
        {
            int prevProfit = INT_MIN;
            for(int j=1; j<N; j++)
            {
                prevProfit = max(prevProfit, dp[i-1][j-1]-A[j-1]);
                dp[i][j] = max(dp[i][j-1], prevProfit+A[j]);
            }
        }
        return dp[K][N-1];
    }
};

int main(){

    int n,k;
    cin >>n >>k;
    
    int v[n];
    for(int i=0; i<n; i++) cin >>v[i];

    Solution obj;
    cout <<obj.maxProfit(k, n, v) <<endl;
    return 0;
}