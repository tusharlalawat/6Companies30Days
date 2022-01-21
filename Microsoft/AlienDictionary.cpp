#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>& visited, vector<vector<int>>& graph, string& ans){
        visited[node] = 1;
        
        for(auto it : graph[node]){
            if(!visited[it]) dfs(it, visited, graph, ans);
        }
        
        char c = node + 'a';
        ans = c + ans;
    }
    
string findOrder(string v[], int n, int k) {
        //code here
        vector< vector<int> > graph(k);
        string s1, s2;
        for(int i=0; i<n-1; i++){
            s1 = v[i];
            s2 = v[i+1];
            
            for(int j=0; j<min(s1.length(), s2.length()); j++){
                if(s1[j] != s2[j]) {
                    graph[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;
                }
            }
        }
        
        vector<int> visited(k, 0);
        string ans = "";
        for(int i=0; i<k; i++){
            if(visited[i] == 0){
                dfs(i, visited, graph, ans);
            }
        }
        
        return ans;
    }

int main() {
    return 0;
}