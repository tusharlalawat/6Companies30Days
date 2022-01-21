#include<bits/stdc++.h>
using namespace std;

// We need to find cycle in the graph

// 0 => Not Visited
// 1 => Processed (traversal of all it's nodes have been completed)
// 2 => Processing (traversal of all the nodes is not completed)
bool isCycle(int node, vector<int>& visited, vector<vector<int>>& v){
    
    if(visited[node] == 2) return true;              // there presents a cycle
    
    visited[node] = 2;
    for(auto it : v[node]){
        if(visited[it] != 1) {                                // Already processed nodes
            if(isCycle(it, visited, v)) return true;      
        }
    }
    
    visited[node] = 1;      // Making the current node processed
    
    return false;          // If it does not contain cycle
}

bool canFinish(int n, vector<vector<int>>& given) {
    
    vector< vector<int> > v(n);
    for(int i=0; i<given.size(); i++) v[given[i][0]].push_back(given[i][1]);
    
    vector<int> visited(n, 0);
    for(int i=0; i<n; i++){   
        if(visited[i] == 0){
            if(isCycle(i, visited, v))     // Can't complete all the courses as it contains a cycle
                return false;
        }
    }
    return true;
}

int main() {
    return 0;
}