#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > fourSum(vector<int> &v, int k) {
    // Your code goes here
    
    int n = v.size();
    vector<vector<int>> ans;
    sort(v.begin(), v.end());
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            
            int target = k - v[i] - v[j];
            int left = j+1;
            int right = n-1;
            
            while(left < right){
                int sum = v[left]+v[right];
                if(sum < target) left++;
                else if(sum > target) right--;
                else {
                    int l = v[left];
                    int r = v[right];
                    
                    ans.push_back({v[i], v[j], v[left], v[right]});
                    while(left < right && v[left] == l) left++;             // To remove duplicate elements
                    while(left < right && v[right] == r) right--;           // To remove duplicate elements
                }
            }
            
            while(j+1 < n && v[j+1] == v[j]) j++;                           // To remove duplicate elements
        }
        while(i+1 < n && v[i+1] == v[i]) i++;                               // To remove duplicate elements
    }
    return ans;
}

int main() {

    return 0;
}