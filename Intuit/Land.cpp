#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(int ROW, int COL, queue<vector<int>> &line, vector<vector<int>>& distance) {
        while(!line.empty()) {
            vector<int> current_cell = line.front(); line.pop();
            int row = current_cell[0];
            int col = current_cell[1];
            int dis = current_cell[2];

            dis = distance[row][col] = min(dis, distance[row][col]);

            //top
            if(row > 0 && (dis + 1) < distance[row - 1][ col]) {
                line.push({row - 1, col, dis + 1});
            }

            //right
            if(col < (COL - 1 )&& (dis + 1) < distance[row][col + 1]) {
                line.push({row, col + 1, dis + 1});
            }

            //bottom
            if(row < (ROW - 1) && (dis + 1) < distance[row + 1][col]) {
                line.push({row + 1, col, dis + 1});
            }

            //left
            if(col > 0 && (dis + 1) < distance[row][col - 1]) {
                line.push({row, col - 1, dis + 1});
            }
        }
    }

    int maxDistance(vector<vector<int>>& grid) {
        int ROW = grid.size();
        int COL = grid[0].size();

        vector<vector<int>> distance(ROW, vector<int>(COL, INT_MAX));
        queue<vector<int>> line;

        int ans = 0;
        for(int i = 0; i < ROW; ++i) {
            for(int j = 0; j < COL; ++j) {
                if(grid[i][j]) {
                    line.push({i, j, 0});
                };
            }
        }

        bfs(ROW, COL, line, distance);

        for(int i = 0; i < ROW; ++i) {
            for(int j = 0; j < COL; ++j) {
                ans = max(ans, distance[i][j]);
            }
        }

        return (ans == 0 || ans == INT_MAX ? -1 : ans);
    }
};

int main() {
    return 0;
}