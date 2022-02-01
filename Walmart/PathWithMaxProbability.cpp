#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& prob, int start, int end) {
        vector<bool> fixed(n, false);
        vector<double> ans(n, 0);
        ans[start] = 1;
        
        vector<vector<pair<double, int>>> graph(n);
        
        for(int i = 0; i < edges.size(); ++i) {
            graph[edges[i][0]].push_back({prob[i], edges[i][1]});
            graph[edges[i][1]].push_back({prob[i], edges[i][0]});
        }
        
        priority_queue<pair<double, int>> pq;
        
        pq.push({1.0, start});
        
        while(!pq.empty()) {
            pair<double, int> entry = pq.top(); pq.pop();
            
            double src_val = entry.first;
            int src_node = entry.second;

            if(!fixed[src_node]) {
                fixed[src_node] = true;
                
                for(auto dest: graph[src_node]) {
                    double probability = dest.first;
                    int dest_node = dest.second;
                    if(ans[dest_node] < src_val * probability) {
                        ans[dest_node] = src_val * probability;
                        pq.push({ans[dest_node], dest_node});
                    }
                }
            }
        }

        return ans[end];
    }
};

int main() {
    return 0;
}