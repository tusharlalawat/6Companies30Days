#include<bits/stdc++.h>
using namespace std;
#define ll long long

int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {    
        ll prod = 1, ans = 0, l = 0, r = 0;
        if(k <= 1) return 0;
        
        while(r < n){
            prod *= (1ll*a[r]);
            while(prod >= k) prod /= a[l++];
            ans += (r - l + 1);
            r++;
        }
        return ans;
    }

int main(){
    int n,k;
    cin >>n >>k;

    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >>arr[i];
    cout <<countSubArrayProductLessThanK(arr, n, k) <<endl;

    return 0;
}