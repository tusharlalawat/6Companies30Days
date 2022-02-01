#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int squaredDistance(vector<int> &a, vector<int> &b) {
        return (a[0] - b[0])*(a[0] - b[0]) + (a[1] - b[1])*(a[1] - b[1]);
    }

    int numberOfBoomerangs(vector<vector<int>>& points) {
        int len =  points.size();

        vector<unordered_map<int, int>> dist(len);
    
        for(int i = 0; i < len; ++i) {
            for(int j = i + 1; j < len; ++j) {
                int distance = squaredDistance(points[i], points[j]);
                ++dist[i][distance];
                ++dist[j][distance];
            }
        }
        
        int ans = 0;

        for(auto point: dist) {
            for(auto d: point) {
                ans += d.second * (d.second - 1);
            }
        }
        
        return ans;
    }
};

int main() {
    return 0;
}