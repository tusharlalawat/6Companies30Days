#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string v[], string s)
    {
        // code here
        int len = s.length();
        vector< vector<string> > ans(len);
        set<string> st;
        
        for(int i=0; i<n; i++) st.insert(v[i]);
        for(int i=0; i<len; i++){
            for(auto it : st){
                if(s.substr(0, i+1) == it.substr(0, i+1))
                    ans[i].push_back(it);
            }
            
            if(ans[i].size() == 0) ans[i].push_back("0");
        }
        
        return ans;
    }
};

int main(){
    int n;
    cin >>n;
    string v[n];
    for(int i=0; i<n; i++) cin >>v[i];
    string s;
    cin >>s;

    Solution obj;
    vector<vector<string>> ans = obj.displayContacts(3, v, s);
    for(auto it : ans){
        for(auto x : it){
            cout <<x <<" ";
        }
        cout <<endl;
    }
    return 0;
}