#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& v) {
        
        int n = v.size();
        int m = v[0].size();
        int fresh = 0;
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(v[i][j] == 2) q.push({i,j});
                if(v[i][j] == 1) fresh++;
            }
        }
        
        int ans = -1; // //initialised to -1 since after each step we increment the time by 1 and initially all rotten oranges started at 0.
        
        int x, y;
        vector<int> dir = {0,1,0,-1,0};
        
        while(!q.empty()){
            int size = q.size();
            
            while(size--) {
                // auto [r,c] = q.front();
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                
                for(int i=0; i<4; i++){
                    x = r + dir[i];
                    y = c + dir[i+1];
                    
                    if(x<0 || x>=n || y<0 || y>=m || v[x][y] != 1) continue;
                    else {
                        v[x][y] = 2;
                        q.push({x,y});
                        fresh--;
                    }
                }
            }
            ans++;
        }
        
        if(fresh > 0) return -1;   //if fresh>0 that means there are fresh oranges left
        if(ans == -1) return 0; //we initialised with -1, so if there were no oranges it'd take 0 mins.
        return ans;
    }
};

int main(){
    int n,m;
    cin >>n >>m;
    
    vector< vector<int> > v(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cin >>v[i][j];
    }

    Solution obj;
    cout <<obj.orangesRotting(v) <<endl;
    return 0;
}