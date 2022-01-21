#include<bits/stdc++.h>
using namespace std;

// Algorithm:- if the vertex d in not recheable from any other nodes expect node c than the edge b/w node c and d is a bridge edge.

void dfs(int node, vector<int> adj[], int c, int d, vector<bool>& visited){
        visited[node] = true;
        
        for(auto it : adj[node]){
            if((node == c && it == d) || (node == d || it == c)) continue;
            if(!visited[it]) dfs(it, adj, c, d, visited);
        }
    }

int isBridge(int V, vector<int> adj[], int c, int d) {
        // Code here
        vector<bool> visited(V, false);
        dfs(c, adj, c, d, visited);
        
        if(!visited[d]) return 1;
        
        return 0;
    }

int main() 
{
    return 0;
}
