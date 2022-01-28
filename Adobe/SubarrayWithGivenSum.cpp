#include<bits/stdc++.h>
using namespace std;

vector<int> subarraySum(int n, vector<int> v, int target){
    int l = 0, sum = 0;
    vector<int> ans;
    for(int i=0; i<n; i++){
        sum += v[i];

        while(sum > target) sum -= v[l++];

        if(sum == target){
            ans.push_back(l+1);
            ans.push_back(i+1);
            return ans;
        }
    }

    ans.push_back(-1);
    return ans;
}

int main() {
    int n, target;
    cin >>n >>target;

    vector<int> v(n);
    for(int &i : v) cin >>i;

    v = subarraySum(n, v, target);
    for(auto it : v) cout <<it <<" ";
    cout <<endl;

    return 0;
}