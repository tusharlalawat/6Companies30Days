#include<bits/stdc++.h>
using namespace std;

vector<int> leaders(int v[], int n){
        // Code here
        
        vector<int> ans;
        ans.push_back(v[n-1]);
        int m = v[n-1];
        for(int i=n-2; i>=0; i--){
            if(v[i] >= m){
                ans.push_back(v[i]);
                m = v[i];
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }

int main(){
    return 0;
}