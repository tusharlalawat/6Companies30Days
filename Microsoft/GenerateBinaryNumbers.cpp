#include<bits/stdc++.h>
using namespace std;

vector<string> generate(int n){

    queue<string> q;
    vector<string> ans;
    q.push("1");

    for(int i=1; i<=n; i++){
        string s = q.front();
        q.pop();
        ans.push_back(s);

        // string p = s;
        q.push(s + "0");
        q.push(s + "1");
    }

    return ans;
}

int main() {
    int n;
    cin >>n;

    vector<string> ans = generate(n);
    for(int i=0; i<n; i++) cout <<ans[i] <<" ";
    cout <<endl;
    return 0;
}