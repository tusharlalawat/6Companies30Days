#include<bits/stdc++.h>
using namespace std;

vector<int> smallestRange(vector<vector<int>>& nums) {
        
    vector<pair<int, int>> v;
    for(int i=0; i<nums.size(); i++){
        for(auto it : nums[i]) v.push_back({it, i});
    }
    
    sort(v.begin(), v.end());
    
    int left = 0, total = 0;
    vector<int> mp(nums.size(), 0);
    vector<int> ans;
    
    for(int i=0; i<v.size(); i++){
        if(mp[v[i].second] == 0) total++;
        mp[v[i].second]++;
        
        if(total == nums.size()){
            while(mp[v[left].second] > 1) --mp[v[left++].second];
            if((ans.size() == 0) || (ans[1]-ans[0]) > v[i].first-v[left].first){
                ans = {v[left].first, v[i].first};
            }
        }
    }
    
    return ans;
}

int main() {
    return 0;
}