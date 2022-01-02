#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long

ull getNthUglyNo(int n) {

    ull ans = 0;
    vector<int> v(n);
    v[0] = 1;
    int ind2 = 0, ind3 = 0, ind5 = 0;
    int n2 = 2, n3 = 3, n5 = 5;

    for(int i=1; i<n; i++){
        ans = min(n2, min(n2, n3));
        v[i] = ans;

        if(ans == n2){
            ind2++;
            n2 = v[ind2]*2;
        }
        else if(ans == n3){
            ind3++;
            n3 = v[ind3]*3;
        }
        else if(ans == n5){
            ind5++;
            n5 = v[ind5]*5;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >>n;
    cout <<getNthUglyNo(n) <<endl;
    return 0;
}