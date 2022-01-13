#include<bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& v, int k) {

    int n = v.size();
    vector<int> ans;
    deque<int> q;

    for(int i=0; i<k; i++){
        while(!q.empty() && v[q.back()] < v[i]) q.pop_back();
        q.push_back(i);
    }

    for(int i=k; i<n; i++){
        ans.push_back(v[q.front()]);

        while(!q.empty() && v[q.back()] < v[i]) q.pop_back();
        while(!q.empty() && q.front() <= i-k) q.pop_front();
        q.push_back(i);
    }
    ans.push_back(v[q.front()]);

    return ans;
}
int main(){
    int n,k;
    cin >>n >>k;

    vector<int> v(n);
    for(int i=0; i<n; i++) cin >>v[i];

    vector<int> ans = maxSlidingWindow(v, k);
    for(int i=0; i<ans.size(); i++) cout <<ans[i] <<" ";
    cout <<endl;
    return 0;
}