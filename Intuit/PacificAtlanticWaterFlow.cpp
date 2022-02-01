#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void pacificBFS(int row, int col, vector<vector<int>>& heights, vector<vector<int>>& visited) {
        
        int m = heights.size();
        int n = heights[0].size();

        if(visited[row][col] == 1) {
            return;
        }

        queue<pair<int, int>> pq;

        pq.push({row, col});
        visited[row][col] = 1;

        while(!pq.empty()) {

            auto current = pq.front(); pq.pop();

            int row = current.first;
            int col = current.second;
            int height = heights[row][col];

            // top
            if(row > 0 && visited[row - 1][col] != 1 && heights[row - 1][col] >= height) {
                pq.push({row - 1, col});
                visited[row - 1][col] = 1;
            }

            // left
            if(col > 0 && visited[row][col - 1] != 1 && heights[row][col - 1] >= height) {
                pq.push({row, col - 1});
                visited[row][col - 1] = 1;
            }

            // right
            if(col < n - 1 && visited[row][col + 1] != 1 && heights[row][col + 1] >= height) {
                pq.push({row, col + 1});
                visited[row][col + 1] = 1;
            }

            // bottom
            if(row < m - 1 && visited[row + 1][col] != 1 && heights[row + 1][col] >= height) {
                pq.push({row + 1, col});
                visited[row + 1][col] = 1;
            }
        }
    }
    
    void atlanticBFS(int row, int col, vector<vector<int>>& heights, vector<vector<int>>& visited, vector<vector<int>>& ans) {
        
        int m = heights.size();
        int n = heights[0].size();

        if(visited[row][col] == 2) {
            return;
        }

        queue<pair<int, int>> pq;

        pq.push({row, col});
        if(visited[row][col] == 1) {
            ans.push_back({row, col});
        }
        visited[row][col] = 2;

        while(!pq.empty()) {

            auto current = pq.front(); pq.pop();

            int row = current.first;
            int col = current.second;
            int height = heights[row][col];

            // top
            if(row > 0 && visited[row - 1][col] != 2 && heights[row - 1][col] >= height) {
                pq.push({row - 1, col});
                if(visited[row - 1][col] == 1) {
                    ans.push_back({row - 1, col});
                }
                visited[row - 1][col] = 2;
            }

            // left
            if(col > 0 && visited[row][col - 1] != 2 && heights[row][col - 1] >= height) {
                pq.push({row, col - 1});
                if(visited[row][col - 1] == 1) {
                    ans.push_back({row, col - 1});
                }
                visited[row][col - 1] = 2;
            }

            // right
            if(col < n - 1 && visited[row][col + 1] != 2 && heights[row][col + 1] >= height) {
                pq.push({row, col + 1});
                if(visited[row][col + 1] == 1) {
                    ans.push_back({row, col + 1});
                }
                visited[row][col + 1] = 2;
            }

            // bottom
            if(row < m - 1 && visited[row + 1][col] != 2 && heights[row + 1][col] >= height) {
                pq.push({row + 1, col});
                if(visited[row + 1][col] == 1) {
                    ans.push_back({row + 1, col});
                }
                visited[row + 1][col] = 2;
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<int>> visited(m, vector<int>(n, 0));
        
        // reach of pacific Ocean
        // 1
        
        for(int i = 0; i < n; ++i) {
            pacificBFS(0, i, heights, visited);
        }
        for(int i = 1; i < m; ++i) {
            pacificBFS(i, 0, heights, visited);
        }

        // reach of Atlantic Ocean
        // if cell == 1, include in ans;
        // 2
        
        vector<vector<int>> ans;

        for(int i = 0; i < n; ++i) {
            atlanticBFS(m - 1, i, heights, visited, ans);
        }
        for(int i = 0; i < m; ++i) {
            atlanticBFS(i, n - 1, heights, visited, ans);
        }
        
        sort(ans.begin(), ans.end());

        return ans;
    }
};

int main() {
    return 0;
}