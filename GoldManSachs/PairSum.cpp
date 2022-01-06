#include<bits/stdc++.h>
using namespace std;

bool canPair(vector<int> v, int k) {
        // Code here.
        int n = v.size();
        if(n%2 != 0) return false;
        
        vector<int> temp(k, 0);
        for(int i=0; i<n; i++){
            temp[(v[i]%k + k)%k]++;
        }
        
        for(int i=0; i<n; i++){
            int rem = (v[i]%k + k)%k;
            if(rem*2 == k){
                if(temp[rem]%2 != 0) return false;
            }
            else if(rem == 0){
                if(temp[rem]%2 != 0) return false;
            }
            else if(temp[rem] != temp[k-rem]) return false;
        }
        return true;
    }

int main(){
    int n, k;
    cin >>n >>k;

    vector<int> v(n);
    for(int i=0; i<n; i++) cin >>v[i];
    cout <<canPair(v, k) <<endl;

    return 0;
}