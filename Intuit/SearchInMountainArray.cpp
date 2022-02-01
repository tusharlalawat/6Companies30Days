#include<bits/stdc++.h>
using namespace std;

int findInMountainArray(int n, vector<int>& v, int target){
    int mid, l = 0, r = n-1, peek = -1;

    // Finding peek element's index
    while(l <= r){
        mid = l + (r-l)/2;
        if(v[mid-1] < v[mid] && v[mid] < v[mid+1]) l = mid+1;
        else if(v[mid-1] > v[mid] && v[mid] > v[mid+1]) r = mid-1;
        else {
            peek = mid;
            break;
        }
    }

    // cout <<"Peek: " <<peek <<", L: " <<l <<", R: " <<r <<endl;

    // Searching in the first half
    l = 0, r = peek;
    while(l <= r){
        mid = l + (r-l)/2;
        if(target < v[mid]) l = mid+1;
        else if(target > v[mid]) r = mid-1;
        else return mid;
    }

    // Searching in the second half
    l = peek, r = n-1;
    while(l <= r){
        mid = l + (r-l)/2;
        if(target < v[mid]) r = mid-1;
        else if(target > v[mid]) l = mid+1;
        else return mid;
    }

    return -1;
}

int main(){
    int n;
    cin >>n;

    vector<int> v(n);
    for(auto &i : v) cin >>i;

    int target;
    cin >>target;

    cout <<"Element found at index: " << findInMountainArray(n, v, target) <<endl;
    return 0;
}