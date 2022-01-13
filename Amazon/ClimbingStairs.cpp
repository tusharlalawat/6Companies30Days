#include<bits/stdc++.h>
using namespace std;

// Works if order matter only
long long ways(int n){
    if(n <= 1) return n;

    int x = 1, y = 1, ans;
    for(int i=2; i<=n; i++){
        ans = x+y;
        y = x;
        x = ans;
    }
    return ans;
}

// Only works if order does not matter
long long countWays(int n)
{
    // your code here
    long long ans = n/2 + 1;
    return ans;
}

int main(){
    int n;
    cin >>n;

    cout <<countWays(n) <<endl;
}