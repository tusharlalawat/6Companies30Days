#include<bits/stdc++.h>
using namespace std;

vector <int> calculateSpan(vector<int>& v, int n)
    {
       // Your code here
        vector<int> ans(n, 1);
        stack<pair<int, int>> st;
        st.push({v[0], 1});
        
        for(int i=1; i<n; i++){
            int count = 1;
            while(!st.empty() && st.top().first <= v[i]){
                ans[i] += st.top().second;
                st.pop();
            }

            st.push({v[i], ans[i]});
        }
        return ans;
    }

int main() {
    int n;
    cin >>n;

    vector<int> v(n);
    for(int i=0; i<n; i++) cin >>v[i];

    v = calculateSpan(v, n);
    for(int i=0; i<n; i++) cout <<v[i] <<" ";
    cout <<endl;

    return 0;
}