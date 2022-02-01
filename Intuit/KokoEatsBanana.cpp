#include<bits/stdc++.h>
using namespace std;

int minEatingSpeed(int n, vector<int>& v, int h){
    int l = 1, r = *max_element(v.begin(), v.end());
    int mid, ans;

    while(l <= r){
        mid = l + (r-l)/2;

        int hours = 0;
        for(auto it : v){
            hours += it/mid;
            if(it%mid != 0) hours += 1;

            if(hours > h) break;
        }

        if(hours <= h){
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
}

int main() {
    int n;
    cin >>n;

    vector<int> v(n);
    for(auto &i : v) cin >>i;

    int hours;
    cin >>hours;

    cout <<"Minimum speed needed is: " <<minEatingSpeed(n, v, hours) <<endl;
    return 0;
}