#include<bits/stdc++.h>
using namespace std;

pair<int, int> findTwoElement(int n, vector<int> v){
    pair<int, int> ans;
    int first, second;
    for(int i=0; i<n; i++){
        int ind = abs(v[i]);
        if(v[ind-1] > 0) v[ind-1] *= -1;
        else first = abs(v[i]);     // If a nuber has -ve valuse(it has been visited twice) thanit will show the repeated number.
    }

    for(int i=0; i<n; i++){
        if(v[i] > 0) second = i+1;    //The index where element value is > 0 is the number missing from the array.
    }
    ans.first = first;
    ans.second = second;
    return ans;
}

int main(){
    int n;
    cin >>n; 
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >>v[i];
    pair<int, int> ans = findTwoElement(n, v);
    cout <<ans.first <<" " <<ans.second <<endl;
    return 0;
}