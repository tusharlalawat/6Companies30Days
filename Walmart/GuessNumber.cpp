#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int maxAmount(int start, int end, vector<vector<int>> &cache) {
        if(end == start) {
            return 0;
        }
        if(end - start == 1) {
            return min(start, end);
        }
        if(cache[start][end] != -1) return cache[start][end];

        int ans = INT_MAX;
        for(int i = start + 1; i < end; ++i) {
            ans = min(ans, i + max(maxAmount(start, i - 1, cache), maxAmount(i + 1, end, cache)));
        }
        
        cache[start][end] = ans;

        return ans;
    }

    int getMoneyAmount(int n) {
        vector<vector<int>> cache(n + 1, vector<int>(n + 1, -1));
        return maxAmount(1, n, cache);
    }
};

int main() {
    return 0;
}