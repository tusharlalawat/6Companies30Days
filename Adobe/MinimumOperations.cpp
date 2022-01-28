#include<bits/stdc++.h>
using namespace std;

int minInsAndDel(vector<int> A, vector<int> B, int n, int m){

    vector<int> v;
    unordered_set<int> st;
    for(int i=0; i<m; i++) st.insert(B[i]);

    for(int i=0; i<n; i++){
        if(st.find(A[i]) != st.end()){
            auto it = lower_bound(v.begin(), v.end(), A[i]);
            if(it == v.end()) v.push_back(A[i]);
            else *it = A[i];
        }
    }

    return n+m-2*v.size();
}

int main() {
    int n, m;
    cin >>n, m;

    vector<int> A(n), B(m);

    for(auto &it : A) cin >>it;
    for(auto &it : B) cin >>it;

    cout <<"Ans is: " <<minInsAndDel(A, B, n, m) <<endl;
    return 0;
}