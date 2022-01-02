#include<bits/stdc++.h>
using namespace std;

vector< vector<string> > Anagrams(vector<string>& v) {
        //code here
        unordered_map<string, vector<string>> mp;
        for(int i=0; i<v.size(); i++){
            string temp = v[i];
            sort(temp.begin(), temp.end());
            mp[temp].push_back(v[i]);
        }
        
        
        vector<vector<string>> ans;
        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }

int main(){
    int n;
    cin >>n;

    vector<string> v(n);
    for(int i=0; i<n; i++) cin >>v[i];

    vector< vector<string> > ans = Anagrams(v);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout <<ans[i][j] <<" ";
        }
        cout <<endl;
    }
    return 0;
}

// Time Complexity:- O(N*M)
// Space Complexity:- O(N*M)
// Where N = number of strings, and m = max characters in a string.