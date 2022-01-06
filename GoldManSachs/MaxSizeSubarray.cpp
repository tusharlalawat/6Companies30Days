#include<bits/stdc++.h>
using namespace std;

// Using Two pointers 
// Time Complexity:- O(N)
// Space Complexity:- O(1)
int minSubArrayLen(int target, vector<int>& v) {
        
        int n = v.size();
        int ans = INT_MAX;
        
        int l=0, r=0, sum=0;
        while(r < n){
            sum += v[r++];
            while(sum >= target){
                ans = min(ans, r-l);
                sum -= v[l++];
            }
        }
        return (ans != INT_MAX) ? ans : 0;
    }

// Using Binary Search 
// Time Complexity:- O(NlogN)
// Space Complexity:- O(N)
int usingBinary(int target, vector<int>& v) {
        
        int n = v.size();
        int ans = INT_MAX;
        vector<int> sum(n+1, 0);
        for(int i=1; i<=n; i++) sum[i] = sum[i-1]+v[i-1];

        for(int i=n; i>=0 && sum[i]>=target; i--){
            int j = upper_bound(sum.begin(), sum.end(), sum[i]-target) - sum.begin();
            ans = min(ans, i-j+1);
        }
        return (ans != INT_MAX) ? ans : 0;
    }

int main(){
    int n, target;
    cin >>n >>target;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >>v[i];
    cout <<minSubArrayLen(target, v) <<endl;
    return 0;
}