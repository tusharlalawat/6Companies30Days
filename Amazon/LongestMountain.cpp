#include<bits/stdc++.h>
using namespace std;

// Using two pointer approach
// Time Complexity:- O(N)
// Space Complexity:- O(1)
class Solution {
public:
    int solve(vector<int>& v, int ind){
        int l = ind-1, r = ind+1;
        if(v[l] >= v[ind] || v[r] >= v[ind]) return 0;
        while(l >= 0 && v[l]<v[l+1]) l--;
        while(r < v.size() && v[r]<v[r-1]) r++;
        return r-l-1;
    }
    int longestMountain(vector<int>& v) {
        
        int n = v.size();
        if(n < 3) return 0;
        int ans = 0;
        
        for(int i=1; i<n-1; i++){
            int temp = solve(v, i);
            if(temp < 3) temp = 0;
            ans = max(temp, ans);
        }
        return ans;
    }
};

int main(){
    int n;
    cin >>n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >>v[i];

    Solution s;
    cout <<s.longestMountain(v) <<endl;
    return 0;
}