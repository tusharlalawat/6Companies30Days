#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        vector<pair<int, int>> eng(n);
        
        long long int MOD = 1e9+7;
        
        for(int i = 0; i < n; ++i) {
            eng[i].first = efficiency[i];
            eng[i].second = speed[i];
        }
        
        sort(eng.rbegin(), eng.rend());
        
        long long int sum = 0;
        long long int ans = INT_MIN;
        
        priority_queue<long long, vector<long long>, greater<long long>> heap;
        
        for(int i = 0; i < k; ++i) {
            heap.push(eng[i].second);
            sum += eng[i].second;
            ans = max(ans, sum*eng[i].first);
        }
        
        for(int i = k; i < n; ++i) {
            heap.push(eng[i].second);
            sum += eng[i].second;
            sum -= heap.top(); heap.pop();
            ans = max(ans, sum*eng[i].first);
        }

        return ans%MOD;
    }
};

int main() {
    return 0;
}