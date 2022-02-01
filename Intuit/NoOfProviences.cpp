#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int N = isConnected.size();

        vector<bool> visited(N, false);

        queue<int> line;

        int province = 0;

        for(int r = 0; r < N; ++r) {
            if(visited[r]) continue;

            line.push(r);
            visited[r] = true;
            
            while(!line.empty()) {
                int current = line.front(); line.pop();
                for(int c = 0; c < N; ++c) {
                    if(isConnected[c][current] && !visited[c]) {
                        line.push(c);
                        visited[c] = true;
                    }
                }
            }

            ++province;
        }
        
        return province;
    }
};

int main() {
    return 0;
}