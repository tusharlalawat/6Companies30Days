#include<bits/stdc++.h>
using namespace std;

vector<string> winner(string arr[],int n){
    
        map<string, int> mp;
        for(int i=0; i<n; i++) mp[arr[i]]++;
        
        int m = -1;
        string ans = "-1";
        for(auto it : mp) {
            m = max(m, it.second);
            // cout <<it.second <<" ";
        }
        
        // cout <<"M: " <<m <<endl;
        for(auto it : mp){
            if(it.second == m){
                if(ans == "-1") ans = it.first;
                else if(it.first < ans) ans = it.first;
            }
        }
        
        vector<string> v(2);
        v[0] = ans;
        v[1] = to_string(m);
        
        return v;
    }

int main() {
    return 0;
}