#include<bits/stdc++.h>
using namespace std;

int findPosition(int n, int m, int k) {
        
        // (n - k + 1) is number of positions before we reach beginning of circle
        // If m is less than this value, then we can simply return (m-1)th position

        if(m <= n-k+1) return m+k-1;         // (m-1)th position starting from k
        m = m - (n-k+1);                    // Removing remaining positions after k
        return (m%n == 0) ? n : m%n;
    }

int main(){
    int n,k,m;       // n => size of circle, m => items to be distributed, k => starting position
    cin >>n >>m >>k;

    cout <<findPosition(n, m, k) <<endl;
    return 0;
}