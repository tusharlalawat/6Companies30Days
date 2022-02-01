#include<bits/stdc++.h>
using namespace std;

bool isCapable(vector<int>& v, int d, int cap){
    int days = 0 , weight = 0;
    for(auto it : v){
        if(weight + it > cap){
            days++;
            weight = it;
        }else {
            weight += it;
        }
    }

    if(days < d) return true;
    return false;
}

int shipWithinDays(int n, vector<int>& v, int d){
    int l = *max_element(v.begin(), v.end());
    int r = INT_MAX;
    int mid, ans;

    while(l <= r){
        mid = l + (r-l)/2;
        if(isCapable(v, d, mid)) {
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >>n;

    vector<int> v(n);
    for(auto &i : v) cin >>i;

    int days;
    cin >>days;

    cout <<"Minimum capacity to ship is: " <<shipWithinDays(n, v, days) <<endl;
    return 0;
}